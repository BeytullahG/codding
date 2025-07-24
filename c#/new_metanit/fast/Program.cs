// Конструкторы, инициализаторы и деконструкторы


// Person tom = new Person();

// class Person
// {
//     string name;
//     int age;
//     public Person()
//     {
//         Console.WriteLine("Создание объекта Person");
//         name = "Tom";
//         age = 37;
//     }
//     public void Print()
//     {
//         Console.WriteLine($"Имя: {name}, возраст: {age}");
//     }
// }


// Person Tom = new ();
// Person Bob = new ("Bob");
// Person sam = new ("Sam", 20);

// Tom.Print();
// Bob.Print();
// sam.Print();

// class Person
// {
//     public string name;
//     public int age;
//     public Person() { name = "Undifined"; age = 18; }
//     public Person(string n) { name = n; age = 18; }
//     public Person(string n, int a) { name = n; age = a; }

//     public void Print()
//     {
//         Console.WriteLine($"name: {name}, age: {age}");
//     }

// }


// Person tom = new();
// Person bob = new("Bob");
// Person sam = new("Sam", 25);
 
// tom.Print();          // Имя: Неизвестно  Возраст: 18
// bob.Print();          // Имя: Bob  Возраст: 18
// sam.Print();          // Имя: Sam  Возраст: 25
// //Цепочка вызова конструкторов
// class Person
// {
//     string name;
//     int age;
//     public Person() : this("Неизвестно")
//     { }
//     public Person(string name) : this("name", 18)
//     { }
//     public Person(string name, int age)
//     {
//         this.name = name;
//         this.age = age;
//     }

//     public void Print() => Console.WriteLine($"name: {name}, age: {age}");
// }


