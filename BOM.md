# Bill of Materials

One set = **2 sticks + 2 desk clamps** (one clamp per stick).
Quantities below cover the whole set. Marketplace listings expire — order by the spec
column; links are search entry points.

| # | Part | Spec | Qty | Source |
|---|------|------|-----|--------|
| 1 | Bearings | 608ZZ, 8×22×7 mm | 8 | [Amazon](https://www.amazon.com/s?k=608ZZ+bearing) |
| 2 | Axis potentiometers | PS5 type, **2.3 kΩ, green body**, 3-pin, ALPS-compatible; 2 per stick | 4 | [Console Customs](https://consolecustoms.com/alps-oem-2k3-potentiometer-for-ps5-dualsense-and-edge-controllers-pair/) · [Amazon](https://www.amazon.com/s?k=PS5+potentiometer+2.3k) |
| 3 | Camera thumbsticks | Joy-Con replacement module, potentiometer type, 5-pin 0.5 mm flex ("3rd gen") | 2 | [Amazon](https://www.amazon.com/s?k=joy-con+joystick+replacement+3rd+generation) |
| 4 | Return springs | Extension: wire 2 mm, 9 coils, free length ≈45 mm, open angled hooks ≈14 mm, zinc ("cot spring", packs of 10) | 2 | [Lee Spring](https://www.leespring.com/extension-springs) |
| 5 | MCU boards | STM32F103C8T6 Blue Pill, **USB-C variant** | 2 | [Amazon](https://www.amazon.com/s?k=STM32F103C8T6+type-c) |
| 6 | Panel USB-C sockets | Female breakout, 4 pads: V, D−, D+, G — **no CC** | 2 | [Amazon](https://www.amazon.com/s?k=usb+c+female+breakout+4+pin) |
| 7 | Host cables | USB A→C, data | 2 | any |
| 8 | Bridge cable | USB C→C — cut open, internal wiring | 1 | any |
| 9 | Copper laminate | FR4, single-sided, 100×200×1.5 mm, 35 µm | 1 | [Amazon](https://www.amazon.com/s?k=copper+clad+fr4+single+sided) |
| 10 | Photo paper | Glossy 220 g/m² A4, laser-rated (or transfer film) | 1 sheet | [Amazon](https://www.amazon.com/200gsm-Quickly-Excellent-Pictures-printers/dp/B0GX7V3743) |
| 11 | Female headers | 1×40, 2.54 mm, THT (PBS-40); cut 2×20 per board | 2 | [LCSC](https://www.lcsc.com/search?q=2.54mm%20female%20header%201x40) |
| 12 | Male header | 1×40, 2.54 mm, THT (PLS-40) | 1 | [LCSC](https://www.lcsc.com/search?q=2.54mm%20male%20header%201x40) |
| 13 | FFC connectors | 0.5 mm, 5-pin, SMT, **front-flip, bottom contact** | 2 | [Amazon](https://www.amazon.com/Csldmcml-Connector-Bottom-Flexible-CS-FPC-0-5-Bottom/dp/B0G2RTY4RL/) |
| 14 | Buttons | Tact switch 6×6×5 mm 4 pins, THT (KAN0611-0501B) | 8 | [Amazon](https://www.amazon.com/s?k=6x6x5+tact+switch) |
| 15 | Wiring kit | DuPont 2.54 mm crimp set ≈620 pcs | 1 | [Amazon](https://www.amazon.com/s?k=dupont+crimp+kit+2.54) |
| 16 | Ribbon cable | 26-way, 1.27 mm pitch, 28 AWG | 1 m | [Amazon](https://www.amazon.com/s?k=26+pin+1.27mm+ribbon+cable) |
| 17 | Cable ties | 3.6×200 mm | 4 | any |
| 18 | Machine screws | M2×6 — thumbstick modules to handle top cover, 2 per module | 4 | hardware store |
| 19 | Wood screws | 2.5×6 / 2.5×10 / 2.5×13 mm, into printed bosses | 1 pack each | hardware store |
| 20 | M4 hardware | Screw M4×60 DIN 967 + nyloc nut M4 | 4 + 4 | hardware store |
| 21 | M8 hardware | Bolt M8×85 + nut + washer | 4 sets | hardware store |
| 22 | Steel tube | Square 15×15×1.2 mm | 1.6 m | steel supplier |
| 23 | Steel tube | Square 20×20×2.0 mm | 0.6 m | steel supplier |
| 24 | Tube end caps | 15×15 mm / 20×20 mm | 8 / 4 | [Amazon](https://www.amazon.com/s?k=square+tube+end+cap) |
| 25 | Felt | Self-adhesive sheet, 100×100 mm | 1 | any |
| 26 | Filament | PLA+ 1.75 mm (eSUN), ≈600 g | 1 spool | [Amazon](https://www.amazon.com/s?k=eSUN+PLA%2B+1.75) |
| 27 | Dust boots | Soft durable PU leather ("eco-leather"), 50×50 cm piece → 2 custom-sewn gaiters; | 1 piece | [Amazon](https://www.amazon.com/s?k=soft+faux+leather+fabric) |

Per clamp (×2): 0.8 m of 15×15, 0.3 m of 20×20, 2× M8 sets, 4 caps 15 mm, 2 caps 20 mm.

## Notes

- **#3:** Joy-Con form factor only; Pro Controller and Hall/TMR modules are not compatible.
- **#4:** measure coil OD before substituting; stock springs come with closed loops —
  the open hooks may need forming.
- **#5:** USB-C variant required by the printed seat; on clone boards check the D+ pull-up
  (1.5 kΩ).

**Consumables:** hot glue · rosin/no-clean flux · solder · IPA · P1000 abrasive · carbide
drills 0.8–1.0 mm · etchant per bath: 100 ml 3% H2O2 + 30 g citric acid + 5 g salt.

**Tools:** 3D printer · laser printer · iron · soldering iron + hot air · multimeter ·
2.54 mm crimp tool · ST-Link V2 · grinder + welder · respirator, safety glasses.

**TODO:** spring coil OD · better dust boot sewing pattern.