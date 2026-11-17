# HOSAS Joystick Set

[Русская версия](#ru) · English

Two-stick controller set (HOSAS — Hands On Stick And Stick) for space flight simulators.
Eight analog axes: six for ship motion, two for camera control. Grips are 3D-printed,
boards are single-sided and suitable for home fabrication by the laser toner transfer
method (LTTM), controllers are STM32 Blue Pill or Arduino Pro Micro.

This document is the current build reference. Separate assembly documentation does not
exist yet; unfinished items are marked `TODO` and listed in [Known gaps](#known-gaps).

![HOSAS joystick set](Image.jpg)

Video review (original sound in Russian): `TODO — YouTube link`

---

## 1. Overview

| Input | Axes | Buttons |
|---|---|---|
| Right grip | 4 | 2 |
| Left grip | 4 | 2 |

| Parameter | Value |
|---|---|
| Controller, current build | STM32 Blue Pill (STM32F103C8T6), USB Custom HID |
| Controller, earlier builds | Arduino Pro Micro (ATmega32U4), supported |
| Axis sensing | Potentiometers → ADC (DMA on STM32) |
| Centering | Return spring |
| Fastening | Wood screws into printed bosses |
| Host interface | USB, no driver installation |
| Desk mount | Welded 20×20 / 15×15 mm steel tube, M8 bolts |

## 2. Repository layout

```
body/                               3D models and print layouts
  Joystick_Base_v0.4.f3d / .step        base, editable source + STEP
  joystick_handle_v0.6.f3d / .step      grip, editable source + STEP
  Base_Print_Layout.3mf                 slicer project, base parts
  Left_Handle_Print_Layout.3mf          slicer project, left grip
  Right_Handle_Print_Layout.3mf         slicer project, right grip
electronics/
  joystick_v4_left/                     KiCad project + joystick_v4-Cu.svg (copper artwork)
  joystick_v4_right/                    KiCad project + joystick_v4-Cu.svg (copper artwork)
firmware/
  Arduino/HOSAS/HOSAS.ino               Pro Micro sketch
  STM32/CJoy/                           STM32CubeIDE project (CJoy.ioc, Core, USB_DEVICE)
  STM32/prebuilt/CJoy.bin               compiled firmware, flash-ready
BOM.md                                Bill of materials
```

One KiCad project per hand. Editable CAD is Fusion 360 (`.f3d`); `.step` is provided for
other CAD systems. STL files are not published — export from the STEP.

## 3. Parts and tools

Bill of materials: [BOM.md](BOM.md).

Tools: 3D printer; laser printer and glossy paper; iron; etching chemicals; carbide drill
bits; soldering iron and hot air; multimeter; crimp tool; ST-Link V2 for STM32 flashing.

## 4. Build

Sequence: print → PCB → assembly → firmware → verification. Test after each stage, not
after final assembly; faults are cheaper to find early.

### 4.1 Printing

Print the four slicer projects in `body/` — 2x base, left grip, right grip. Parts are already
arranged with supports. Scale 100 %: potentiometer seats and screw bosses are
dimension-critical.

| Parameter | Value |
|---|---|
| Material | eSun PLA+ |
| Nozzle | 0.4 |
| Slicer | Orca Slicer v2.4.1 |

### 4.2 PCB fabrication (LTTM)

**Current PCB design is for STM32 only.**
`TODO add Arduino Pro Micro PCB design`
Artwork: `electronics/joystick_v4_*/joystick_v4-Cu.svg` (copper layer).
Project files: `.kicad_pro`, `.kicad_sch`, `.kicad_pcb` — KiCad 9.0.

Home fabrication is recommended for a first prototype: a fab-house order adds weeks of
lead time before a layout error becomes apparent.

1. **Print the artwork** on glossy paper with a laser printer, **it is already mirrored**, at 1:1 scale.
   Verify the scale against a known 2.54 mm header pitch before transfer.
2. **Prepare the laminate:** wet 1000-grit abrasive, then degrease with alcohol.
3. **Transfer:** iron near maximum (cotton setting), toner side down, about two minutes
   with firm, even pressure.
4. **Remove the paper:** soak in hot soapy water for 30 minutes, then roll the paper off
   with the fingers under water. Toner remaining on copper indicates the correct
   temperature; smeared toner means too hot, toner left on paper means too cold.
5. **Etch:** 100 ml hydrogen peroxide + 30 g citric acid + 5 g sodium chloride. Keep the
   vessel on a water bath or other mild heat source and agitate periodically. Clearing of
   the copper between tracks takes 20–30 minutes.
6. **Finish:** strip the toner with fine abrasive, drill with carbide bits (standard bits
   tear the tracks), trim the board to size.
7. **Tin and solder:** rosin or no-clean flux only; acid fluxes are not acceptable.
   Through-hole components from the solder side, SMD on the component side with hot air.
   A double-sided board is made as two single-sided boards joined by wire links.
8. **Verify:** check every track for continuity and every adjacent pair for shorts with a
   multimeter. Use crimped DuPont connectors for detachable wiring.

Read [Safety](#5-safety) before etching.

### 4.3 Mechanical assembly

Detailed instructions: `TODO`. Current sequence:

1. Mount the potentiometers in their designed seats and check alignment over the full
   travel of each axis before fixing them.
2. Fasten the boards and mechanical parts with wood screws into the printed bosses.
   Plastic threads tolerate limited torque; overtightening breaks them.
3. Fit the return spring under tension. Confirm free travel and reliable centering of
   both axes before closing the grip.
4. Wire the axes and buttons according to the schematic, then verify direction and
   endpoint values on the host before final closure.

### 4.4 Firmware

**Arduino Pro Micro** — `firmware/Arduino/HOSAS/HOSAS.ino`

Open the sketch in Arduino IDE, select board `Arduino Micro`, install 
https://github.com/MHeironimus/ArduinoJoystickLibrary, upload, then verify in the host joystick panel.

**STM32 Blue Pill** — `firmware/STM32/CJoy/`

STM32CubeIDE project generated from `CJoy.ioc`. Target STM32F103C8Tx, linker script
`STM32F103C8TX_FLASH.ld`. USB class: Custom HID; the report descriptor is defined in
`USB_DEVICE/App/usbd_custom_hid_if.c`. Axes are read by ADC with DMA
(`Core/Src/adc.c`, `Core/Src/dma.c`), buttons through GPIO.

- Build: import the project into STM32CubeIDE and build.
- Flash without building: `firmware/STM32/prebuilt/CJoy.bin`.
- Upload: ST-Link V2 over SWD (SWDIO, SWCLK, GND, 3V3), or the factory USART1 bootloader
  with BOOT0 = 1 using STM32CubeProgrammer. Flash address `0x08000000`.
- Axis limits, inversion, and deadzone: `TODO — document the constants in Core/Src/main.c`.

The Blue Pill costs about half as much as the Pro Micro and offers higher performance;
the flashing procedure is more involved.

### 4.5 Verification and binding

1. Confirm that both sticks enumerate as separate USB devices.
2. Open the host joystick panel (Windows: `joy.cpl`) and check all axes and all
   buttons: full range, stable center, no jitter, correct direction.
3. Assign the axes in the simulator, invert where required, apply a deadzones,
   and set response curves for the translation axes.

## 5. Safety

Respiratory and eye protection are required when abrading copper laminate and when
etching; work in a ventilated area. Welding and abrasive cutting require the corresponding
protective equipment.

Spent etchant must not be discharged into the drain. Neutralise it with iron filings or
steel offcuts; decant only the clear liquid after neutralisation and dispose of the solid
residue as household waste.

The project is provided "as is", without warranty. Fabrication and use are undertaken at
the operator's own risk.

## 6. Desk mount

The mount holds the grip at elbow height and leaves the keyboard and mouse area free.
Construction: 20×20 and 15×15 mm steel tube, cut, welded, roller-painted, with felt pads on
all desk contact surfaces to prevent slipping and scratching.

Cut list and drawings: `TODO — not published yet`.

## Known gaps

- Step-by-step mechanical assembly instructions.
- Desk mount cut list and drawings.
- Third-revision defects and planned changes.

Corrections and additions are welcome through Issues.

## License

| Scope | License |
|---|---|
| Firmware (`firmware/`) | Apache License 2.0 |
| CAD models, PCB designs, documentation, media | CC BY 4.0 |

Copying, modification, and redistribution, including commercial use, are permitted.
Firmware redistribution requires retention of the LICENSE and NOTICE files and a notice
stating that files were modified. Redistribution of design files requires credit, a link
to this repository, a link to the license, and an indication of changes.

> Based on the HOSAS Joystick project by Aleh-Zamzhytski and Kommande —
> https://github.com/Aleh-Zamzhytski/KommOK-HOSAS (hardware: CC BY 4.0, firmware: Apache-2.0).

Attribution on physical builds, photographs, and videos is appreciated but not required.
Third-party components under `firmware/STM32/CJoy/Drivers` and `Middlewares` retain their
own licenses (see the `LICENSE.txt` files in those directories).

---

<a id="ru"></a>

## Комплект HOSAS Джойстиков

[English version](#hosas-joystick-set) · Русский

Комплект из двух джойстиков (HOSAS — Hands On Stick And Stick) для космических
симуляторов. Восемь аналоговых осей: шесть на движение корабля, две на камеру.
Рукояти печатаются на 3D-принтере, платы односторонние и изготавливаются дома по
лазерно-утюжной технологии (ЛУТ), контроллеры — STM32 Blue Pill или Arduino Pro Micro.

Видеообзор: `TODO — ссылка на YouTube`

Раздел повторяет английскую версию выше. При расхождении актуальна английская.

### 1. Обзор

| Орган управления | Оси | Кнопки |
|---|---|---|
| Правый джойстик | 4 | 2 |
| Левый джойстик | 4 | 2 |

| Параметр | Значение |
|---|---|
| Контроллер, текущая версия | STM32 Blue Pill (STM32F103C8T6), USB Custom HID |
| Контроллер, ранние версии | Arduino Pro Micro (ATmega32U4), поддерживается |
| Оси | Потенциометры → АЦП (DMA на STM32) |
| Возврат в центр | Возвратная пружина |
| Крепёж | Саморезы по дереву в печатные колодцы |
| Интерфейс | USB, установка драйверов не требуется |
| Крепление к столу | Сварная профильная труба 20×20 / 15×15 мм, болты М8 |

### 2. Файлы репозитория

Структура приведена в [английском разделе](#2-repository-layout): имена файлов и каталогов
от языка не зависят.

Один проект KiCad на каждую руку. Редактируемые модели — Fusion 360 (`.f3d`), `.step`
предоставлен для других CAD-систем. STL можно получить экспортом из STEP.

### 3. Детали и инструмент

Спецификация деталей: [BOM.md](BOM.md).

Инструмент: 3D-принтер; лазерный принтер и глянцевая бумага; утюг; реактивы для травления;
свёрла из карбида вольфрама; паяльник и фен; мультиметр; кримпер; ST-Link V2 для прошивки STM32.

### 4. Сборка

Последовательность: печать → плата → сборка → прошивка → проверка. Контроль выполняется
после каждого этапа, а не после окончательной сборки: так дефекты обходятся дешевле.

#### 4.1 Печать

Печатаются четыре набора деталей из трёх файлов в `body/`: база — дважды (по одной на
каждый джойстик), левый джойстик, правый джойстик. Детали уже расставлены с поддержками.
Масштаб 100 %: посадочные места потенциометров и колодцы под саморезы критичны к размерам.

| Параметр | Значение |
|---|---|
| Материал | eSun PLA+ |
| Сопло | 0,4 мм |
| Слайсер | Orca Slicer v2.4.1 |

#### 4.2 Изготовление платы (ЛУТ)

Текущая разводка рассчитана только на STM32. `TODO — добавить плату под Arduino Pro Micro`

Картинка для перевода на текстолит: `electronics/joystick_v4_*/joystick_v4-Cu.svg`.
Файлы проекта: `.kicad_pro`, `.kicad_sch`, `.kicad_pcb` — KiCad 9.0.

Для первого прототипа рекомендуется домашнее изготовление: заказ на фабрике добавляет
недели ожидания, прежде чем обнаружится ошибка в разводке.

1. **Печать рисунка** на глянцевой бумаге лазерным принтером, масштаб 1:1.
   Рисунок **уже отзеркален**, повторно зеркалить не нужно. Перед переносом проверить
   масштаб по заведомо известному шагу выводов 2,54 мм.
2. **Подготовка текстолита:** мокрая наждачная бумага P1000, затем обезжиривание IPA спиртом.
3. **Перенос:** утюг почти на максимум (режим «хлопок»), тонером вниз, около двух минут
   с равномерным прижимом.
4. **Снятие бумаги:** замачивание в горячей воде с мылом на 30 минут, затем скатывание
   бумаги пальцами под водой. Тонер остался на меди — температура выбрана верно;
   расплылся — утюг перегрет; остался на бумаге — недогрет.
5. **Травление:** 100 мл перекиси водорода + 30 г лимонной кислоты + 5 г поваренной соли.
   Ёмкость на водяной бане или другом слабом нагреве, периодически помешивать.
   Медь между дорожками уходит за 20–30 минут.
6. **Финиш:** снять тонер мелкой наждачкой, сверлить карбидным сверлом (обычное рвёт
   дорожки), обрезать плату по размеру.
7. **Лужение и пайка:** только канифоль или безотмывочный флюс; кислотные флюсы
   недопустимы. DIP-компоненты — с обратной стороны, SMD — феном с лицевой.
   Двусторонняя плата изготавливается как две односторонние, соединённые проволочными
   перемычками.
8. **Контроль:** прозвонить мультиметром каждую дорожку на обрыв и каждую соседнюю пару
   на замыкание. Разъёмные соединения — обжатые контакты DuPont.

Перед травлением прочитать [раздел 5](#5-безопасность).

#### 4.3 Механическая сборка

Подробная инструкция: `TODO`. Текущая последовательность:

1. Установить потенциометры в посадочные места и проверить показания для каждой оси до окончательного крепления.
2. Крепить платы и механику саморезами по дереву в печатные колодцы. Резьба в пластике
   держит ограниченный момент; перетяжка её срывает.
3. Установить возвратную пружину с натягом. До финальной сборки рукояти убедиться в свободном
   ходе и надёжном возврате обеих осей в центр.
4. Развести оси и кнопки по схеме, затем проверить направление и крайние значения
   на компьютере.

#### 4.4 Прошивка

**Arduino Pro Micro** — `firmware/Arduino/HOSAS/HOSAS.ino`

Открыть скетч в Arduino IDE, выбрать плату `Arduino Micro`, установить библиотеку
[ArduinoJoystickLibrary](https://github.com/MHeironimus/ArduinoJoystickLibrary),
загрузить, проверить в панели игровых устройств.

**STM32 Blue Pill** — `firmware/STM32/CJoy/`

Проект STM32CubeIDE, сгенерированный из `CJoy.ioc`. Плата STM32F103C8Tx, linker script
`STM32F103C8TX_FLASH.ld`. Класс USB — Custom HID; дескриптор отчёта задан в
`USB_DEVICE/App/usbd_custom_hid_if.c`. Оси читаются АЦП с DMA (`Core/Src/adc.c`,
`Core/Src/dma.c`), кнопки — через GPIO.

- Сборка: импортировать проект в STM32CubeIDE и собрать.
- Прошивка без сборки: `firmware/STM32/prebuilt/CJoy.bin`.
- Загрузка: ST-Link V2 по SWD (SWDIO, SWCLK, GND, 3V3) либо штатный загрузчик USART1
  при BOOT0 = 1 через STM32CubeProgrammer. Адрес `0x08000000`.
- Пределы осей, инверсия и мёртвая зона: `TODO — описать константы в Core/Src/main.c`.

Blue Pill примерно вдвое дешевле Pro Micro при большей производительности; процедура
прошивки сложнее.

#### 4.5 Проверка и назначение осей

1. Убедиться, что оба джойстика определяются как отдельные USB-устройства.
2. Открыть панель игровых устройств (Windows: `joy.cpl`) и проверить все оси и кнопки:
   полный диапазон, устойчивый центр, отсутствие дрожания, верное направление.
3. Назначить оси в симуляторе, при необходимости инвертировать, задать мёртвые зоны
   и кривые отклика для осей смещения.

### 5. Безопасность

При зачистке текстолита и травлении обязательны респиратор и защитные очки; работать
в проветриваемом помещении. Сварка и абразивная резка требуют соответствующих средств
защиты.

Отработанный раствор не сливается в канализацию. Он нейтрализуется железными опилками
или стальными обрезками; после нейтрализации сливается только прозрачная жидкость,
твёрдый остаток утилизируется как бытовой отход.

Проект предоставляется «как есть», без гарантий. Изготовление и использование —
на риск исполнителя.

### 6. Крепление к столу

Крепление удерживает рукоять на уровне локтя и оставляет свободными место на столе для клавиатуры и мыши.
Конструкция: профильная труба 20×20 и 15×15 мм, резка, сварка, окраска валиком,
войлочные накладки на всех площадках, касающихся стола, — против скольжения и царапин.
Крепление изготавливается отдельно для каждого джойстика.

Раскрой и чертежи: `TODO — ещё не опубликованы`.

### Известные пробелы

- Пошаговая инструкция по механической сборке.
- Раскрой и чертежи крепления к столу.
- Дефекты третьей ревизии и планируемые изменения.

Исправления и дополнения принимаются через Issues.

### Лицензия

| Область | Лицензия |
|---|---|
| Прошивка (`firmware/`) | Apache License 2.0 |
| 3D-модели, платы, документация, медиа | CC BY 4.0 |

Копирование, изменение и распространение, включая коммерческое использование, разрешены.
При распространении прошивки обязательны сохранение файлов LICENSE и NOTICE и указание
на внесённые изменения. При распространении файлов конструкции обязательны указание
авторства, ссылка на репозиторий, ссылка на лицензию и отметка об изменениях.
Полные условия — в [английском разделе](#license).

> Based on the HOSAS Joystick project by Aleh-Zamzhytski and Kommande —
> https://github.com/Aleh-Zamzhytski/KommOK-HOSAS (hardware: CC BY 4.0, firmware: Apache-2.0).

Указание авторства на физических сборках, фотографиях и видео приветствуется,
но не обязательно.

Сторонние компоненты в `firmware/STM32/CJoy/Drivers` и `Middlewares` сохраняют
собственные лицензии (см. файлы `LICENSE.txt` в этих каталогах).