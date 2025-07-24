namespace TaskApp;

using System;
using System.Collections.Generic;

public class TaskManager
{
    private List<Task> Tasks = new();
    private int nextId = 1;
    public void AddTask(string title, string description, DateTime dueDate)
    {
        var task = new Task
        {
            Id = nextId++,
            Title = title,
            Description = description,
            DueDate = dueDate,
            IsCompleted = false
        };
        Tasks.Add(task);
        Console.WriteLine("Задача добавлена!");
    }

    public void ShowAll()
    {
        if (Tasks.Count == 0)
        {
            Console.WriteLine("Список задач пуст.");
            return;
        }

        foreach (Task task in Tasks)
        {
            Console.WriteLine(task);
            Console.WriteLine(new string('-', 40));
        }
    }

    public void MarkCompleted(int id)
    {
        Task task = null;

        foreach (var t in Tasks)
        {
            if (t.Id == id)
            {
                task = t;
                break;
            }
        }
        if (task != null)
        {
            task.IsCompleted = true;
            Console.WriteLine("Задача выполнена!");
        }
        else
        {
            Console.WriteLine("Задача не найдена");
        }
    }

    public void DeleteTask(int id)
    {
        bool found = false;
        for (int i = 0; i < Tasks.Count; i++)
        {
            if (Tasks[i].Id == id)
            {
                Tasks.RemoveAt(i);
                found = true;
                break;
            }
        }
        if (found)
        {
            Console.WriteLine("Задача удалена");
        }
        else
        {
            Console.WriteLine("Задача не найдена");
        }
    }
}

