import pandas as pd
import requests
import json
import csv

company = ['AAPL', 'IBM', 'AMZN', 'MSFT', 'TSLA', 'GOOGL', 'META', 'LYFT', 'INTC', 'JBLU']


#function to get the company name
def get_name(json):
    name = json_data['Meta Data']['2. Symbol']
    return name

#function to convert data into csv
def get_csv(json, name):
    values = []
    headers = []
    for i in json_data['Time Series (Daily)']:
        headers.append(i)
        values.append(json_data['Time Series (Daily)'][i])
    df = pd.DataFrame(values)
    df.set_axis(headers, axis=0, copy=True)
    df.to_csv(f'stock_data_{get_name(json)}.csv')



#loop for each company
for i in company:
    response = requests.get(f'https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol={i}&apikey=<your_api_key>')
    print(response.status_code)
    data = response.text
    json_data = json.loads(data)
    get_csv(json_data, get_name(json_data))