#!/usr/bin/env python3
"""
Simple Serial Monitor GUI (Tkinter + pyserial)
Save as serial_monitor.py and run: python serial_monitor.py
"""
import tkinter as tk
from tkinter import ttk, scrolledtext, messagebox
import threading
import queue
import time
import serial
import serial.tools.list_ports

BAUDS = ["9600","19200","38400","57600","115200"]

class SerialMonitor:
    def __init__(self, root):
        self.root = root
        root.title("Simple Serial Monitor")
        self.ser = None
        self.read_thread = None
        self.stop_event = threading.Event()
        self.q = queue.Queue()

        frm = ttk.Frame(root, padding=8)
        frm.grid(sticky="nsew")
        root.rowconfigure(0, weight=1)
        root.columnconfigure(0, weight=1)

        # Top controls
        top = ttk.Frame(frm)
        top.grid(sticky="ew")
        ttk.Label(top, text="Port:").grid(row=0, column=0, padx=4)
        self.port_combo = ttk.Combobox(top, width=15, state="readonly")
        self.port_combo.grid(row=0, column=1, padx=4)
        ttk.Button(top, text="Refresh", command=self.refresh_ports).grid(row=0, column=2, padx=4)

        ttk.Label(top, text="Baud:").grid(row=0, column=3, padx=4)
        self.baud_combo = ttk.Combobox(top, values=BAUDS, width=10, state="readonly")
        self.baud_combo.set(BAUDS[-1])
        self.baud_combo.grid(row=0, column=4, padx=4)

        self.connect_btn = ttk.Button(top, text="Connect", command=self.toggle_connect)
        self.connect_btn.grid(row=0, column=5, padx=6)

        # Log area
        self.log = scrolledtext.ScrolledText(frm, wrap="none", height=20, state="disabled")
        self.log.grid(row=1, column=0, sticky="nsew", pady=8)
        frm.rowconfigure(1, weight=1)
        frm.columnconfigure(0, weight=1)

        # Bottom send
        bottom = ttk.Frame(frm)
        bottom.grid(sticky="ew")
        self.entry = ttk.Entry(bottom)
        self.entry.grid(row=0, column=0, sticky="ew", padx=4)
        bottom.columnconfigure(0, weight=1)
        ttk.Button(bottom, text="Send", command=self.send_line).grid(row=0, column=1, padx=4)
        ttk.Button(bottom, text="Clear", command=self.clear_log).grid(row=0, column=2, padx=4)
        ttk.Button(bottom, text="Save", command=self.save_log).grid(row=0, column=3, padx=4)

        self.refresh_ports()
        self.root.after(100, self.process_incoming)

    def refresh_ports(self):
        ports = [p.device for p in serial.tools.list_ports.comports()]
        self.port_combo['values'] = ports
        if ports and not self.port_combo.get():
            self.port_combo.set(ports[0])

    def toggle_connect(self):
        if self.ser and self.ser.is_open:
            self.disconnect()
        else:
            self.connect()

    def connect(self):
        port = self.port_combo.get()
        baud = int(self.baud_combo.get() or 115200)
        if not port:
            messagebox.showwarning("No port", "Select a serial port first.")
            return
        try:
            self.ser = serial.Serial(port, baud, timeout=0.1)
        except Exception as e:
            messagebox.showerror("Connection failed", str(e))
            self.ser = None
            return
        self.stop_event.clear()
        self.read_thread = threading.Thread(target=self.reader, daemon=True)
        self.read_thread.start()
        self.connect_btn.config(text="Disconnect")
        self.log_write(f"Connected to {port} @ {baud}\n")

    def disconnect(self):
        self.stop_event.set()
        if self.read_thread:
            self.read_thread.join(timeout=0.5)
        if self.ser:
            try:
                self.ser.close()
            except Exception:
                pass
        self.ser = None
        self.connect_btn.config(text="Connect")
        self.log_write("Disconnected\n")

    def reader(self):
        # reads incoming bytes and enqueue lines
        buf = bytearray()
        while not self.stop_event.is_set():
            try:
                data = self.ser.read(1024)
                if data:
                    buf.extend(data)
                    while b'\n' in buf:
                        line, _, buf = buf.partition(b'\n')
                        try:
                            text = line.decode(errors='replace')
                        except:
                            text = repr(line)
                        self.q.put(text + "\n")
                else:
                    time.sleep(0.01)
            except Exception as e:
                self.q.put(f"[ERROR reading serial: {e}]\n")
                break

    def process_incoming(self):
        # move queued lines into the text widget
        try:
            while True:
                line = self.q.get_nowait()
                self.log_write(line)
        except queue.Empty:
            pass
        self.root.after(100, self.process_incoming)

    def send_line(self):
        text = self.entry.get()
        if not text:
            return
        if not (self.ser and self.ser.is_open):
            messagebox.showwarning("Not connected", "Connect to a serial port first.")
            return
        try:
            self.ser.write((text + "\r\n").encode())
            self.log_write(f"> {text}\n")
            self.entry.delete(0, tk.END)
        except Exception as e:
            messagebox.showerror("Send failed", str(e))

    def log_write(self, msg):
        self.log.configure(state="normal")
        self.log.insert(tk.END, msg)
        self.log.see(tk.END)
        self.log.configure(state="disabled")

    def clear_log(self):
        self.log.configure(state="normal")
        self.log.delete("1.0", tk.END)
        self.log.configure(state="disabled")

    def save_log(self):
        try:
            content = self.log.get("1.0", tk.END)
            fname = f"serial_log_{int(time.time())}.txt"
            with open(fname, "w", encoding="utf-8") as f:
                f.write(content)
            messagebox.showinfo("Saved", f"Log saved to {fname}")
        except Exception as e:
            messagebox.showerror("Save failed", str(e))

    def on_close(self):
        self.disconnect()
        self.root.destroy()

if __name__ == "__main__":
    root = tk.Tk()
    app = SerialMonitor(root)
    root.protocol("WM_DELETE_WINDOW", app.on_close)
    root.mainloop()
