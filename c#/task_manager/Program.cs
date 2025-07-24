using TaskApp;
TaskManager manager = new();

while (true)
{
    Console.WriteLine("\n==== TASK MANAGER ====");
    Console.WriteLine("1. Добавить задачу");
    Console.WriteLine("2. Показать все задачи");
    Console.WriteLine("3. Отметить задачу как выполненную");
    Console.WriteLine("4. Удалить задачу");
    Console.WriteLine("0. Выход");
    Console.Write("Выберите пункт: ");

    string input = Console.ReadLine();
    Console.WriteLine();

    switch (input)
    {
        case "1":
            Console.WriteLine("Название: ");
            string title = Console.ReadLine();
            Console.WriteLine("Описание: ");
            string desc = Console.ReadLine();
            Console.WriteLine("Срок (гггг.мм.дд): ");
            DateTime date = DateTime.Parse(Console.ReadLine());
            manager.AddTask(title, desc, date);
            break;
        case "2":
            manager.ShowAll();
            break;
        case "3":
            Console.Write("Введите ID задачи: ");
            int idToComplete = int.Parse(Console.ReadLine());
            manager.MarkCompleted(idToComplete);
            break;
        case "4":
            Console.Write("Введите ID задачи: ");
            int idToDelete = int.Parse(Console.ReadLine());
            manager.DeleteTask(idToDelete);
            break;
        case "0":
            return;
        default:
            Console.WriteLine("Некорректный ввод");
            break;

    }
    
}