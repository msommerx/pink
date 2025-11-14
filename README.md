# Steuerung für die PINK

## Hardware

https://docs.espressif.com/projects/esp-idf/en/v5.3.1/esp32s3/hw-reference/esp32s3/user-guide-devkitc-1.html

https://docs.espressif.com/projects/esp-idf/en/v5.3.1/esp32s3/_images/ESP32-S3_DevKitC-1_pinlayout_v1.1.jpg

###  GPIO Belegung

| GPIO | Funktion | Bezeichnung                     | Schaltschrank |
| ---- | -------- | ------------------------------- | ------------- |
| 04   | DI 01    | Drehschalter Stellung 1         |               |
| 05   | DI 02    | Drehschalter Stellung 2         |               |
| 06   | DI 03    | Drehschalter Stellung 3         |               |
| 07   | DI 04    | Drehschalter Stellung 4         |               |
| 15   | DO 01    | 24 V Relais Eckventil Bypass    | 12Y4, 20S5    |
| 16   | DO 02    | 24 V Relais Eckventil Rezipient | 12Y2, 18S1    |
| 17   | DO 03    | 24 V Relais Vorpumpe            |               |
| 18   | DO 04    | 24 V Relais Turbopumpe          |               |


## Vakuumablauf

1. Bypassleitung auf  
   Leitung von Turbo zum Rezipienten zu  
   Drehschieberpumpe ein
2. Wenn Vordruck erreicht ist, Bypassleitung schließen  
   Leitung zur Turbo öffnen
3. Wenn Turbo evakuiert ist, Turbo einschalten, Eckventil zum Rezipienten öffnen

VP: Vorpumpe, Drehschieberpumpe  
TP: Turbopumpe  
EV_BP: Eckventil Bypass: 12Y4, 20S5  
EV_RE: Eckventil Rezipient: 12Y2, 18S1   

Gesteuert durch einen mehrpoligen Schalter

| Schalterstellung | Digital IN | Digital OUT | Bezeichnung | Schaltzustand |
| ---------------- | ---------- | ----------- | ----------- | ------------- |
| 1                | DI 01      | DO 01       | EV_BP       | 0             |
|                  |            | DO 02       | EV_RE       | 0             |
|                  |            | DO 03       | VP          | 0             |
|                  |            | DO 04       | TP          | 0             |
| 2                | DI 02      | DO 01       | EV_BP       | 1             |
|                  |            | DO 02       | EV_RE       | 0             |
|                  |            | DO 03       | VP          | 1             |
| 3                | DI 03      | DO 01       | EV_BP       | 0             |
|                  |            | DO 02       | EV_RE       | 1             |
|                  |            | DO 03       | VP          | 1             |
| 4                | DI 04      | DO 01       | EV_BP       | 0             |
|                  |            | DO 02       | EV_RE       | 1             |
|                  |            | DO 03       | VP          | 1             |
|                  |            | DO 04       | TP          | 1             |


