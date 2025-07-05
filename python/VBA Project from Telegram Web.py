import pandas as pd
from openpyxl import load_workbook
from pathlib import Path

FILE_PATH = "/Users/bejtullahgadzimirzoev/codding/python/Алгоритмы_питон/Transport Company Data.xlsx"

# === Загрузка таблицы ===
def load_table(sheet_name):
    try:
        return pd.read_excel(FILE_PATH, sheet_name=sheet_name)
    except Exception as e:
        print(f"Ошибка при загрузке: {e}")
        return pd.DataFrame()

# === Добавление строки ===
def add_row(sheet_name, row_data):
    try:
        wb = load_workbook(FILE_PATH)
        ws = wb[sheet_name]
        ws.append(row_data)
        wb.save(FILE_PATH)
        print("Строка добавлена.")
    except Exception as e:
        print(f"Ошибка: {e}")

# === Получение авто водителя ===
def get_driver_cars(driver_id):
    drivers = load_table("Drivers")
    cars = load_table("Cars")
    row = drivers[drivers["ID"] == driver_id]
    if row.empty:
        return "Водитель не найден."
    car_id = row.iloc[0]["ID автомобиля"]
    car = cars[cars["ID"] == car_id]
    return car if not car.empty else "Авто не найдено."

# === Средний расход ===
def average_fuel_consumption(car_id):
    fuel = load_table("Fuel")
    data = fuel[fuel["ID автомобиля"] == car_id]
    if data.empty:
        return "Нет данных."
    total_liters = data["Литры"].sum()
    total_km = data["Пробег (км)"].sum()
    if total_km == 0:
        return "Недостаточно данных."
    return round((total_liters / total_km) * 100, 2)

# === Расход на топливо ===
def total_fuel_cost(car_id):
    fuel = load_table("Fuel")
    data = fuel[fuel["ID автомобиля"] == car_id]
    if data.empty:
        return "Нет данных."
    return data["Сумма"].sum()

# === ТО авто ===
def service_summary(car_id):
    service = load_table("Service")
    data = service[service["ID автомобиля"] == car_id]
    if data.empty:
        return "Нет записей."
    return data.shape[0], data["Стоимость"].sum()

# === Пробег по рейсам ===
def total_trip_mileage(car_id):
    trips = load_table("Trips")
    data = trips[trips["ID автомобиля"] == car_id]
    return data["Пробег (км)"].sum() if not data.empty else 0

def main():
    while True:
        print("\n=== Действия ===")
        print("1. Показать авто по ID водителя")
        print("2. Средний расход топлива (ID авто)")
        print("3. Общая сумма на топливо (ID авто)")
        print("4. Сводка по ТО (ID авто)")
        print("5. Общий пробег по рейсам (ID авто)")
        print("0. Выход")

        choice = input("Выберите действие: ")

        if choice == "1":
            driver_id = int(input("Введите ID водителя: "))
            print(get_driver_cars(driver_id))

        elif choice == "2":
            car_id = int(input("Введите ID авто: "))
            print(f"Средний расход: {average_fuel_consumption(car_id)} л/100км")

        elif choice == "3":
            car_id = int(input("Введите ID авто: "))
            print(f"Общие затраты на топливо: {total_fuel_cost(car_id)} руб.")

        elif choice == "4":
            car_id = int(input("Введите ID авто: "))
            result = service_summary(car_id)
            if isinstance(result, tuple):
                print(f"Количество ТО: {result[0]}, Сумма: {result[1]} руб.")
            else:
                print(result)

        elif choice == "5":
            car_id = int(input("Введите ID авто: "))
            print(f"Общий пробег: {total_trip_mileage(car_id)} км")

        elif choice == "0":
            print("Выход.")
            break

        else:
            print("Неверный выбор, попробуйте снова.")

if __name__ == "__main__":
    if not Path(FILE_PATH).exists():
        print(f"Файл {FILE_PATH} не найден.")
    else:
        main()
