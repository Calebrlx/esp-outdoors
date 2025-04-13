This example uses the ESPAsyncWebServer library and SPIFFS filesystem. Make sure you have these installed via the Arduino IDE library manager:
	-	ESPAsyncWebServer
	-	AsyncTCP (dependency)
	-	ESP32 filesystem uploader plugin (optional but recommended)

Upload files to ESP32 SPIFFS
In Arduino IDE, select Tools > ESP32 Sketch Data Upload to upload the data folder content


data/
├── index.html
├── style.css
├── script.js
└── inventory.json


Connect phone to the Wi-Fi network:
SSID: OutdoorStuff
Password: outdoor123


Open browser and navigate to: 
http://outdoors.stuff




How it works:
	-	The ESP32 serves as a standalone access point (OutdoorStuff).
	-	A DNS server redirects all DNS requests to the ESP32, effectively making it a captive portal.
	-	Inventory data is hosted locally in SPIFFS storage, making it available offline.
	-	UI is responsive and intuitive, perfect for offline inventory management in the field.
