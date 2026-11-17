# Bill of Materials

[Русская версия](#ru) · English

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
| 6 | Panel USB-C sockets | Female breakout, 4 pads: V, D−, D+, G | 2 | [Amazon](https://www.amazon.com/s?k=usb+c+female+breakout+4+pin) |
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
- **#5:** USB-micro variant may be used, in that case you need another cable to connect USB-C socket and controller;
  on clone boards check the D+ pull-up (1.5 kΩ).

**Consumables:** hot glue · rosin/no-clean flux · solder · IPA · P1000 abrasive · carbide
drills 0.8–1.0 mm · etchant per bath: 100 ml 3% H2O2 + 30 g citric acid + 5 g salt.

**Tools:** 3D printer · laser printer · iron · soldering iron + hot air · multimeter ·
2.54 mm crimp tool · ST-Link V2 · grinder + welder · respirator, safety glasses.

**TODO:** better dust boot sewing pattern.

---

<a id="ru"></a>

## Список Материалов

[English version](#bill-of-materials) · Русский

Один комплект = **2 джойстика + 2 крепления к столу** (по одному на джойстик).
Количества указаны на весь комплект. Лоты на маркетплейсах исчезают — заказывать
по колонке «Спецификация»; ссылки — точки входа в поиск.

Раздел повторяет английскую версию выше. При расхождении актуальна английская.

| № | Деталь | Спецификация | Кол-во | Источник |
|---|--------|--------------|--------|----------|
| 1 | Подшипники | 608ZZ, 8×22×7 мм | 8 | [Ozon](https://ozon.by/product/podshipnik-608zz-cityaun-komplekt-10-sht-1561781544) |
| 2 | Потенциометры осей | Тип PS5, **2,3 кОм, зелёный корпус**, 3 вывода, ALPS-совместимые; по 2 на джойстик | 4 | [Ozon](https://ozon.by/product/zapchast-dlya-igrovoy-konsoli-dlya-playstation-5-potentsiometr-2-3-kom-dlya-3d-stika-1840329143) |
| 3 | Стики камеры | Модуль замены Joy-Con, потенциометрический, шлейф 5-pin 0,5 мм ("3rd gen") | 2 | [Ozon](https://ozon.by/product/mehanizm-3d-stika-dlya-joy-con-nintendo-switch-light-oled-dzhoystika-zapchast-dlya-geympada-1004540723) |
| 4 | Возвратные пружины | Растяжение: проволока 2 мм, 9 витков, свободная длина ≈45 мм, открытые угловые зацепы ≈14 мм, оцинковка («пружина для раскладушки», упаковка 10 шт) | 2 | [WB](https://www.wildberries.by/catalog/178151646/detail.aspx) |
| 5 | Платы МК | STM32F103C8T6 Blue Pill, **вариант с USB-C** | 2 | [Ozon](https://ozon.by/product/otladochnaya-plata-stm32f103c8t6-type-c-64-kb-72-mgts-1sht-2830093346) |
| 6 | Панельные гнёзда USB-C | Розетка на плате, 4 площадки: V, D−, D+, G | 2 | [Ozon](https://ozon.by/product/gnezdo-type-c-na-plate-komplekt-5-shtuk-2165897320) |
| 7 | Кабели к хосту | USB A→C, data | 2 | [WB](https://www.wildberries.by/catalog/211356932/detail.aspx) |
| 8 | Кабель-мост | USB C→C — разрезать на внутреннюю разводку | 1 | [WB](https://www.wildberries.by/catalog/298084710/detail.aspx) |
| 9 | Текстолит | FR4, односторонний, 100×200×1,5 мм, 35 мкм | 1 | [Ozon](https://ozon.by/product/steklotekstolit-odnostoronniy-100x200x1-5-mm-35-00-35-mkm-1-sht-rexant-633934612) |
| 10 | Фотобумага | Глянцевая фотобумага A4, 220 г/м² (допустимо 200–260 г/м²) | 1 лист | [WB](https://www.wildberries.by/catalog/376526943/detail.aspx) |
| 11 | Разъем DuPont 2.54 "мама" | 1×40, 2,54 мм, THT (PBS-40); резать 2×20 на плату | 2 | [Ozon](https://ozon.by/product/razem-na-platu-30-pin-shag-2-54mm-shtyrevoy-odnoryadnyy-shteker-gnezdo-komplekt-5sht-1617789721) |
| 12 | Разъем DuPont 2.54 "папа" | 1×40, 2,54 мм, THT (PLS-40) | 1 | [Ozon](https://ozon.by/product/shtyrevye-odnoryadnye-razemy-na-platu-papa-pls-40-pryamye-40-pin-2-54-mm-10-shtuk-pld-razem-1046480730) |
| 13 | Разъёмы FFC | 0,5 мм, 5-pin, SMT, **front-flip, нижние контакты** | 2 | [WB](https://www.wildberries.by/catalog/85712216/detail.aspx) |
| 14 | Кнопки | Тактовая 6×6×5 мм, 4 вывода, THT (KAN0611-0501B) | 8 | [Ozon](https://ozon.by/product/taktovaya-knopka-6h6h5mm-kan0611-0501b-10sht-1787748670) |
| 15 | Набор DuPont клемм | Обжимной набор DuPont 2,54 мм, ≈620 шт | 1 | [Ozon](https://ozon.by/product/razem-dupont-2-54-mm-nabor-620-sht-vilka-i-rozetka-obzhimnye-ip54-dlya-maketirovaniya-na-arduino-5032796426) |
| 16 | Шлейф | 26 жил, шаг 1,27 мм, 28 AWG | 1 м | [Ozon](https://ozon.by/product/shleyf-rc-shag-1-27mm-26pin-28awg-seryy-rc-26-1metr-3495571324) |
| 17 | Стяжки | 3,6×200 мм | 4 | [Ozon](https://ozon.by/product/styazhka-homut-neylonovaya-plastikovaya-krepezh-3-6h200mm-2169594332) |
| 18 | Винты M2×6 | Крепление модулей стиков к верхней крышке рукояти, по 2 на модуль | 4 | [Ozon](https://ozon.by/product/samorez-m2h6-10-shtuk-1749878453) |
| 19 | Саморезы | 2,5×6 / 2,5×10 / 2,5×13 мм, в печатные колодцы | по 1 упаковке | [Ozon](https://www.wildberries.by/catalog/238797507/detail.aspx); [Ozon](https://www.wildberries.by/catalog/238797510/detail.aspx); [Ozon](https://www.wildberries.by/catalog/447935207/detail.aspx) |
| 20 | Крепёж M4 | Винт M4×60 DIN 967 + самоконтрящаяся гайка M4 | 4 + 4 | [Ozon](https://ozon.by/product/vint-otsinkovannyy-s-polukrugloy-golovkoy-m4h60-mm-dlya-krepleniya-mebelnoy-ruchki-din967-20-shtuk-2146593737); [Ozon](https://ozon.by/product/gayka-m4-otsinkovannaya-samokontryashchayasya-25-shtuk-2517119545) |
| 21 | Крепёж M8 | Болт M8×85 + гайка + шайба | 4 комплекта | [Ozon](https://ozon.by/product/bolt-s-shestigrannoy-golovkoy-polnaya-rezba-din-933-m8h85-mm-10-sht-1281379020); [Ozon](https://ozon.by/product/gayka-m8-otsinkovannaya-shestigrannaya-din-934-100-sht-krepstor-2934861488); [Ozon](https://ozon.by/product/shayba-m8-ploskaya-otsinkovannaya-50-shtuk-3276087388) |
| 22 | Профтруба | Квадратная 15×15×1,2 мм | 1,6 м | [Ozon](https://ozon.by/product/truba-profilnaya-15x15x1-5-mm-2metra-1sht-5545902886) |
| 23 | Профтруба | Квадратная 20×20×2,0 мм | 0,6 м | [Ozon](https://ozon.by/product/truba-profilnaya-20h20h2-0-mm-1m-h-1-sht-4636970310) |
| 24 | Заглушки профтрубы | 15×15 мм / 20×20 мм | 8 / 4 | [WB](https://www.wildberries.by/catalog/240860562/detail.aspx); [WB](https://www.wildberries.by/catalog/1941160529/detail.aspx) |
| 25 | Войлок | Самоклеящийся лист 100×100 мм | 1 | [WB](https://www.wildberries.by/catalog/178715993/detail.aspx) |
| 26 | Филамент | PLA+ 1,75 мм (eSUN), ≈600 г | 1 катушка | [Ozon](https://ozon.by/product/plastik-dlya-3d-pechati-pla-pla-material-dlya-3d-printera-esun-1-75-mm-1kg-belaya-white-306557972) |
| 27 | Чехлы | Мягкая прочная экокожа (PU), 50×50 см → 2 пыльника, пошив на заказ | 1 | [Ozon](https://ozon.by/product/ekokozha-dlya-avto-i-mebelnaya-ekokozha-chernaya-50-h-140-sm-280280430) |

На одно крепление (×2): 0,8 м трубы 15×15; 0,3 м трубы 20×20; 2 комплекта M8;
4 заглушки 15 мм; 2 заглушки 20 мм.

### Примечания

- **№3:** только форм-фактор Joy-Con; модули Pro Controller и Hall/TMR несовместимы.

**Расходники:** термоклей · канифоль/безотмывочный флюс · припой · изопропиловый спирт ·
наждачка P1000 · твердосплавные свёрла 0,8–1,0 мм · раствор на ванну:
100 мл 3% H₂O₂ + 30 г лимонной кислоты + 5 г соли.

**Инструмент:** 3D-принтер · лазерный принтер · утюг · паяльник + фен · мультиметр ·
кримпер 2,54 мм · ST-Link V2 · болгарка + сварка · респиратор, защитные очки.

**TODO:** улучшенная выкройка пыльника.