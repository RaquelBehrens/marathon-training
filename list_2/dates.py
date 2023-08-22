from datetime import datetime, timedelta

n = int(input())

for i in range(1, n+1):
    input_date = input().strip()
    passed = int(input())

    date = datetime.strptime(input_date, '%Y-%B-%d')
    new_date = date + timedelta(days=passed)
    output_date = new_date.strftime('%Y-%B-%d')

    print(f"Case {i}: {output_date}")
