import pandas as pd
import requests
import json
import csv

# get IBM

response = requests.get(f'https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=IBM&apikey=demo')
print(response.status_code) # status code = 200 is successful
data = response.text
json_data = json.loads(data)

print(json_data)

values = []
headers = []

for i in json_data['Time Series (Daily)']:
  headers.append(i)
  values.append(json_data['Time Series (Daily)'][i])

df = pd.DataFrame(values)
print(df)

df.set_axis(headers, axis=0, copy=True)

name = json_data['Meta Data']['2. Symbol']
df.to_csv(f'stock_data_{name}.csv')
