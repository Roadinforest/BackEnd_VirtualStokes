import requests
import os

# List of company symbols
companies = [ 'GOOGL', 'META', 'LYFT', 'INTC', 'JBLU']

# Directory where you want to save the files (in the "Data" folder)
save_folder = os.path.join(os.getcwd(), 'Data')

# Ensure the "Data" folder exists, create if not
os.makedirs(save_folder, exist_ok=True)

# Base URL for Alpha Vantage API
base_url = "https://www.alphavantage.co/query"

# API key (replace 'demo' with your actual API key)
api_key = "DWZLG88TOJCYVNY8"

# Function to download CSV for a company
def download_company_csv(symbol):
    url = f"{base_url}?function=TIME_SERIES_MONTHLY_ADJUSTED&symbol={symbol}&apikey={api_key}&datatype=csv"
    filename = os.path.join(save_folder, f"{symbol}_monthly_data.csv")
    response = requests.get(url)
    if response.status_code == 200:
        with open(filename, 'wb') as f:
            f.write(response.content)
        print(f"File saved successfully: {filename}")
    else:
        print(f"Failed to download file for {symbol}. Status code: {response.status_code}")

# Loop through each company and download CSV
for company in companies:
    download_company_csv(company)
