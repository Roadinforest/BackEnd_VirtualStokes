import os
import pandas as pd
import requests
import json

# List of companies
company = ['AAPL', 'IBM', 'AMZN', 'MSFT', 'TSLA', 'GOOGL', 'META', 'LYFT', 'INTC', 'JBLU']

# Function to get the company name from JSON data
def get_name(json_data):
    return json_data['Meta Data']['2. Symbol']

# Function to convert JSON data to CSV and save in the 'Data' folder
def get_csv(json_data, name):
    # Extract dates and values
    dates = list(json_data['Time Series (Daily)'].keys())
    values = [list(json_data['Time Series (Daily)'][date].values()) for date in dates]

    # Create DataFrame
    df = pd.DataFrame(values, index=dates, columns=['Open', 'High', 'Low', 'Close', 'Volume'])
    df.index = pd.to_datetime(df.index)  # Convert index to datetime if needed

    # Define the directory 'Data' if it doesn't exist
    data_dir = 'Data'
    if not os.path.exists(data_dir):
        os.makedirs(data_dir)

    # Save to CSV in the 'Data' folder
    file_path = os.path.join(data_dir, f'stock_data_{name}.csv')
    df.to_csv(file_path)
    print(f"Data saved for {name} at {file_path}")

# Loop through each company
for symbol in company:
    api_key = '<your_api_key>'
    response = requests.get(f'https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol={symbol}&apikey={api_key}')

    if response.status_code == 200:
        json_data = response.json()
        name = get_name(json_data)
        get_csv(json_data, name)
    else:
        print(f"Failed to fetch data for {symbol}. Status code: {response.status_code}")
