from PIL import Image
img = Image.open("128.jpeg").resize((128,128)).convert("RGB")
data = []
for y in range(128):
    for x in range(128):
        r,g,b = img.getpixel((x,y))
        color = ((r & 0xF8)<<8) | ((g & 0xFC)<<3) | (b>>3)
        data.append(color)
with open("myImage.h", "w") as f:
    f.write("const uint16_t myImage[16384] PROGMEM = {")
    f.write(",".join(str(x) for x in data))
    f.write("};")
