[Перелік лекцій](README.md)

# Hash-функція

Розрізняють декілька способів ідентіфікації: контрольні суми, контроль CRC, хешування и цифровий підпис - Такі базові засоби аутентіфікації при ціфровій передачі Даних.

Контрольні суми - найбільш простий способ Перевірки цілісності Даних, что передаються в цифровому виде, при якому обчіслюється контрольна сума ПОВІДОМЛЕННЯ (певне значення, Пожалуйста и ідентіфікує цифрову інформацію).

## Поняття хеш-функції

**Хеш-функцією (hash function)** називається математична чи інша функція, яка для рядка довільної довжини обчислює деяке ціле значення або деякий інший рядок фіксованої довжини. Математично це можна записати так:

`h = H (M)`,

де `М` - вихідне повідомлення, зване іноді прообразом , а `h` - результат, званий значенням хеш-функції (а також хеш-кодом або дайджестом повідомлення).

Сенс хеш-функції полягає у визначенні характерного ознаки прообразу - значення хеш-функції. цезначення зазвичай має певний фіксований розмір, наприклад, 64 або 128біт. Хеш-код може бути в подальшому проаналізовано для вирішення будь-якої задачі. Так наприклад,хешування може застосовуватися для порівняння даних: якщо у двох масивів даних хеш-коди різні, масиви гарантовано розрізняються; якщо однакові - масиви, швидше за все, однакові. У загальному випадку однозначної відповідності між вихідними даними і хеш-кодом немає через те, що кількість значень хеш-функцій завжди менше, ніж варіантів вхідних даних. Отже, існує безліч вхідних повідомлень, що дають однакові хеш-коди (такі ситуації називаються колізіями). Імовірність виникнення колізій відіграє важливу роль в оцінці якості хеш-функцій.

Хеш-функції широко застосовуються в сучасній криптографії.

найпростіша хешфункція може бути складена з використаннямоперації "сума по модулю 2" в такий спосіб: отримуємо вхідні рядок, складаємо все байти по модулю 2 і байт -результат повертаємо в якості значення хеш-фукнции. Довжина значення хеш-функції складе в цьому випадку 8 біт незалежно від розміру вхідного повідомлення.

Наприклад, нехай вихідне повідомлення, перекладене в цифровий вигляд, було наступним (у шістнадцятковому форматі):

3E 54 A0 1F B4

Переведемо повідомлення в двійковий вигляд, запишемо байти один під одним і складемо біти в кожному стовпчику по модулю 2:
```
0011 1110
0101 0100
1010 0000
0001 1111
1101 0100
----------
0110 0101
```

Результат ( 0110 0101 (2) або 65 (16) ) і буде значенням хеш-функції.

Однак таку хеш-функцію можна використовувати для криптографічних цілей, наприклад для формування електронного підпису, так як досить легко змінити зміст підписаного повідомлення, не змінюючи значення контрольної суми.

Тому розглянута хеш функція не годиться для криптографічних застосувань. У криптографії хеш функція вважається хорошою, якщо важко створити два прообразу з однаковим значенням хеш-функції, а також, якщо у виходу функції немає явної залежності від входу.

Сформулюємо основні вимоги, що пред'являються до криптографічних хеш-функцій:

*   хеш-функція повинна бути застосовна до повідомлення будь-якого розміру;
*   обчислення значення функції має виконуватися досить швидко;
*   при відомому значенні хеш-функції має бути важко (практично неможливо) знайти відповідний прообраз `M`;
*   при відомому повідомленні `M` має бути важко знайти інше повідомлення `M'` з таким же значенням хеш-функції, як у вихідного повідомлення;
*   має бути важко знайти будь-яку пару випадкових видів повідомлень з однаковим значенням хеш-функції;
*   Стійкість до колізій (колізій іншого роду). Колізією для хеш-функції назівається така пара значень `m` та `m'`, `m ≠ m'` , для якої `H(m) = H(m')`. Так як Кількість можливий відкритих текстів більше числа можливий значень згортки, то для деякої згортки знайдеться багато прообразів ⇒ колізії для хеш функцій обов'язково існують. Например, нехай довжина хеш прообразу 6 бітів, довжина згортки 4 біта. Тоді число різніх.

![](img/10-003.jpg)

## Колізії хеш-функції

Створити хеш-функцію, яка задовольняє всім перерахованим вимогам - завдання непросте. Необхідно також пам'ятати, що на вхід функції надходять дані довільного розміру, а хеш-результат не повинен виходити однаковим для даних різного розміру.

В даний час на практиці в якості хеш-функцій застосовуються функції, що обробляють вхідний повідомлення блок за блоком і обчислюють хеш значення h i для кожного блоку M i вхідного повідомлення по залежностям виду

`h i = H (M i , h i-1 )`,

де h i-1 - результат, отриманий при обчисленні хеш-функції для попереднього блоку вхідних даних.

В результаті вихід хеш-функції h n є функцією від всіх n блоків вхідного повідомлення.

Розробка хеш-функцій, что задовольняють всім вимоги, - складне завдання. Практично відповідають ЦІМ вимоги хеш-функції з групи алгоритмів MD и SHA.

алгоритм

описание

Довжина хешу, біт

Примітка

MD2

одностороння функція

128

Повільніше, чем MD4 и MD5

MD4

одностороння функція

128

MD5

одностороння функція

128

Складніше, но повільніше, чем MD4.

NAVAL

одностороння функція

довжина різна

Модіфікація MD5, но більш стійка до атак

SHA

одностороння функція

160

Вікорістовується в DSA

SHA-1 , SHA-256, SHA-384, SHA- 512

Оновлена версія SHA

SHA-1 створює хеш довжина 160 біт, SHA-256 - довжина 256 біт и т.д.

## Теми для самостійного вивчення

1.  Принципи роботи алгоритмів групи CRC
2.  Принципи роботи алгоритмів групи MD
3.  Принципи роботи алгоритмів групи SHA
4.  Недоліки алгоритмів групи MD

## Контрольні питання

1.  Що таке хеш-функція?
2.  Яке призначення хеш-функцій?
3.  Які алгоритми хешування ви знаєте?
4.  В чому головна відмінність процесів хешування та шифрування?