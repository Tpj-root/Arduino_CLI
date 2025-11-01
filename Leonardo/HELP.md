
arduino-cli core install arduino:avr



where@slave:~$ ls /dev/ttyACM* /dev/ttyUSB* 2>/dev/null
 /dev/ttyACM0
where@slave:~$ sudo dmesg | grep tty
[sudo] password for where: 
[    0.183341] printk: legacy console [tty0] enabled
[   13.792220] systemd[1]: Created slice system-getty.slice - Slice /system/getty.
[ 3534.382008] cdc_acm 5-2:1.0: ttyACM0: USB ACM device
where@slave:~$ 




Simple ways 👇

**1️⃣ Plug board → run:**

```bash
ls /dev/ttyACM* /dev/ttyUSB* 2>/dev/null
```

Check which one appears **after plugging** your Leonardo — that’s your port.

**2️⃣ Use `dmesg`:**

```bash
dmesg | grep tty
```

Near the end you’ll see lines like:

```
cdc_acm 1-1.2:1.0: ttyACM0: USB ACM device
```

→ means your port is `/dev/ttyACM0`.

**3️⃣ Use Arduino CLI:**

```bash
arduino-cli board list
```

Shows something like:

```
Port         Type              Board Name  FQBN
/dev/ttyACM0 Serial Port (USB) Arduino Leonardo arduino:avr:leonardo
```

That’s the correct port to set in the Makefile.




✅ Perfect — your board is detected at **`/dev/ttyACM0`**.

You can safely set this line in your Makefile:

```make
PORT=/dev/ttyACM0
```

Now `make upload` will correctly flash your Arduino Leonardo.







where@slave:~/Desktop/MY_GIT/Arduino_CLI/Leonardo/Project_00_Hello$ make upload 
/home/where/Desktop/MY_GIT/Arduino_CLI/Leonardo/Project_00_Hello/tools/arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:leonardo HelloLeonardo
avrdude: ser_open(): can't open device "/dev/ttyACM0": Permission denied
Failed uploading: uploading error: exit status 1
make: *** [Makefile:53: upload] Error 1
where@slave:~/Desktop/MY_GIT/Arduino_CLI/Leonardo/Project_00_Hello$ 



That’s a **Linux permission issue** — your user doesn’t have access to the serial port.
Fix it easily 👇

### 🔧 Option 1 (permanent fix)

Add your user to the **`dialout`** group:

```bash
sudo usermod -a -G dialout $USER
```

Then log out and back in (or reboot).
After that, `/dev/ttyACM0` will be writable.

---

### ⚙️ Option 2 (temporary fix)

Run upload as root:

```bash
sudo make upload
```

(Not recommended long term.)

---

### ✅ Check access

After logging in again:

```bash
ls -l /dev/ttyACM0
```

You should see something like:

```
crw-rw---- 1 root dialout ...
```

and your user should now belong to the `dialout` group (`groups` command to confirm).






cd ~/Arduino/libraries/Keyboard
wget https://raw.githubusercontent.com/arduino/ArduinoCore-avr/master/libraries/Keyboard/src/KeyboardLayout.h




https://github.com/arduino-libraries/Keyboard/tree/master

~/Arduino/libraries/Keyboard/KeyboardLayout.h


