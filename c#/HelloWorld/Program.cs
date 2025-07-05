// {
//     Console.WriteLine("first block");
//     {
//         Console.WriteLine("second block");
//     }
// }

// Console.WriteLine("Enter your name: ");
// string? name = Console.ReadLine();
// Console.WriteLine("Enter your age: ");
// int age = Convert.ToInt32(Console.ReadLine());
// Console.WriteLine($"Hello {name}!");
// Console.WriteLine($"Your age: {age}");





// int x1 = 5;
// int z1 = --x1; // z1=4; x1=4
// Console.WriteLine($"{x1} - {z1}");

// int x2 = 5;
// int z2 = x2--; // z2=5; x2=4
// Console.WriteLine($"{x2} - {z2}");



// int a = 3;
// int b = 5;
// int c = 40;
// int d = c---b*a;    // a=3  b=5  c=39  d=25
// Console.WriteLine($"a={a}  b={b}  c={c}  d={d}");


// byte a = 4;
// byte b = (byte)(a + 64);
// Console.WriteLine(b);

// Условные конструкции
// // #1
// Console.WriteLine("Enter number a: ");
// int a = Convert.ToInt32(Console.ReadLine());
// Console.WriteLine("Enter number b: ");
// int b = Convert.ToInt32(Console.ReadLine());
// if (a<b)
//     Console.WriteLine($"{a} < {b}");
// else if (a>b)
//     Console.WriteLine($"{a}>{b}");
// else 
//     Console.WriteLine($"{a} = {b}");

// #3
// Console.WriteLine("enter number: ");
// int a = Convert.ToInt32(Console.ReadLine());
// if (a==5 || a == 10)
//     Console.WriteLine("Число либо равно 5, либо равно 10");
// else 
//     Console.WriteLine("Неизвестное число");


// #5

// Console.WriteLine("Enter your summ: ");
// Double summ = Convert.ToDouble(Console.ReadLine());
// if (summ < 100)
//     Console.WriteLine($"result: {summ + (summ*0.05) + 15}");
// else if (summ >= 100 && summ <= 200)
//     Console.WriteLine($"result: {summ + (summ*0.07) + 15}");
// else if (summ > 200)
//     Console.WriteLine($"result: {summ + (summ*0.1) + 15}");

// Циклы
// // #1
// Console.WriteLine("enter the deposit amount: ");
// decimal amount = Convert.ToDecimal(Console.ReadLine());
// Console.WriteLine("enter number of month: ");
// int month = Convert.ToInt32(Console.ReadLine());
// decimal result = amount;
// for (int i = 1; i<=month; i++)
//     result += result * 0.07M;
// Console.WriteLine($"result: {result}");


// #2
// Console.WriteLine("enter the deposit amount: ");
// decimal amount = Convert.ToDecimal(Console.ReadLine());
// Console.WriteLine("enter number of month: ");
// int month = Convert.ToInt32(Console.ReadLine());
// decimal result = amount;
// int i = 1;
// while(i <= month){
//     result += result * 0.07M;
//     i++;
// }

// Console.WriteLine($"result: {result}");


// #3
// for (int i = 1; i<= 9; i++){
//     for (int j = 1; j<=9; j++){
//         Console.WriteLine($"{i} * {j} = {i*j}");
//     }
// }

// #4
// Console.WriteLine("Введите число n1 от 0 до 10: ");
// int n1, n2; 
// while (true){
//     int nf = Convert.ToInt32(Console.ReadLine());
//     if (nf>0 && nf<=10){
//         n1 = nf;
//         break;
//     }
//     else Console.WriteLine("Вы ввели число не из разрешенного диапазона");
// }
// Console.WriteLine("Введите число n2 от 0 до 10: ");
// while (true){
//     int ns = Convert.ToInt32(Console.ReadLine());
//     if (ns>0 && ns<=10){
//         n2 = ns;
//         break;
//         }
//     else Console.WriteLine("Вы ввели число не из разрешенного диапазона");
// }

// Console.WriteLine($"Произведение = {n1 * n2}");




// int[] numbers = {-4, -3, -2, -1, 0, 1, 2, 3, 4};
// int n = numbers.Length;
// int k = n/2;
// int temp;

// for (int i=0; i<k; i++){
//     temp = numbers[i];
//     numbers[i] = numbers[n - i - 1];
//     numbers[n-i-1] = temp;
// }

// foreach(int number in numbers){
//     Console.WriteLine($"{number}\t");
// }



// void SayHelloRu()
// {
//     Console.WriteLine("привет");
// }

// void SayHelloEn()
// {
//     Console.WriteLine("hello");
// }

// void SayHelloArab()
// {
//     Console.WriteLine("Assalamualeykum");
// }

// Console.WriteLine("enter your language ru/en/arab: ");
// string language = Console.ReadLine();


// switch(language){
//     case "en":
//         SayHelloEn();
//         break;
//     case "ru":
//         SayHelloRu();
//         break;
//     case "arab":
//         SayHelloArab();
//         break;
// }


DayTime time_now = DayTime.Morning;

PrintMessage(time_now);
PrintMessage(DayTime.Afternoon);
PrintMessage(DayTime.Evening);
PrintMessage(DayTime.Night);

void PrintMessage(DayTime dayTime)
{
    switch (dayTime)
    {
        case DayTime.Morning:
            Console.WriteLine("Good morning");
            break;
        case DayTime.Afternoon:
            Console.WriteLine("Good afternoon");
            break;
        case DayTime.Evening:
            Console.WriteLine("Good evening");
            break;
        case DayTime.Night:
            Console.WriteLine("Good night");
            break;
    }
}



enum DayTime
{
    Morning,
    Afternoon,
    Evening,
    Night
}







