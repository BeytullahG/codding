// class Person
// {
//     public string name = "Undifind";
//     public int age;

//     public Person()
//     {
//         Console.WriteLine("Создание объекта person");
//         name = "Tom";
//         age = 37;
//     }
//     public void Print()
//     {
//         Console.WriteLine($"Name: {name}, age: {age}");
//     }
// }


class Person
{
    public string name;
    public int age;
    public Person() { name = "неизвестно"; age = 18; }
    public Person(string n) { name = n; age = 19; }
    public Person(string n, int a) { name = n; age = a; }
    public void Print()
    {
        Console.WriteLine($"Name: {name}, age: {age}");
    }
}



















