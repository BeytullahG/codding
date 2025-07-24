namespace TaskApp;

using System;

public class Task
{
    public int Id { get; set; }
    public string? Title { get; set; }
    public string? Description { get; set; }
    public DateTime DueDate { get; set; }
    public bool IsCompleted { get; set; }

    public override string ToString()
    {
        return $"{Id}.{Title} - {(IsCompleted ? "Выполнено" : "В процессе")} (до {DueDate:d}) \nОписание: {Description}";
    }
}