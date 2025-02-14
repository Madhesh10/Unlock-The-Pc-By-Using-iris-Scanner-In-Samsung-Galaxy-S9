import serial
import keyboard

ser = serial.Serial('COM3', 115200)  # Change COM3 to your actual port

while True:
    data = ser.readline().decode().strip()
    if data == "UNLOCK":
        print("Unlocking PC...")
        keyboard.press_and_release('ctrl + alt + del')
