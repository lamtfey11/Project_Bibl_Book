--------------------
класс человек:

________поля________

- почта
- фамилия
- имя
- отчество
- возраст
- пароль
- статус

_____________________
---------------------

---------------------
класс библиотекарь(человек):

________поля________

- банковская карта
- кол-во денег

______методы______

- смотреть посоветовшие книги(плат или беслпат) и вносить или не вносить их в библиотеку и удалять их из файла с советами
- удалять историю 
- добавлять лично в файл книги, как плат, так и бесплат
- внести банкосвкую карту(set)
- посмотреть дениги(get)
- диструктор(все данные записывает в файл)

______________________
---------------------

---------------------
класс читатель(человек):

________поля________

- банковская карта
- кол-во денег
- вектор книг с возрастом, автором, которые взял бесплатно
- вектор книг, которые купил

______методы______

- брать книгу, если она есть и соотвествует возростному ограничению(из файла с книгами(с кол-вом книг) вычитается книга)+(действия записываются в историю)
- вернуть книгу обратно в библиотеку(в этот файл она возращается)+(действия записываются в историю)
- посоветовать книгу библиотекарю(в файл для советов библиоткарю, который он может читать, отправлеся книга(название, автор, возраст))
- купить книгу, если есть деньги(в файлк с платными книгами есть ещё цена)+(действия записываются в историю)+деньги деляться всем библиотекарям
- внести карту или поменять карту(set для поля)
- внести деньги в аккаунт(set для поля)
- диструктор(все данные записывает в файл с акк(книгами))

______________________
---------------------


файлы:
- аккаунты с почтой(почта, фио, возраст, пароль, статус)
- книги, которые посоветовали(название, автор, возраст, цена(если есть))
- книги беспалтные(название, автор, возраст, кол-во)
- книги платные(название, автор, возраст, цена, кол-во)
- банк пользователей после ухода с аккаунта(почта, его книги, карта, деньги)
- банк библиотекарей после ухода с аккаунта(почта, деньги)
- история (почта, что сделал)
