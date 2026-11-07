import urllib.request

url = "https://archive.ics.uci.edu/ml/machine-learning-databases/00291/airfoil_self_noise.dat"
filename = "airfoil_self_noise.dat"

print(f"Downloading {filename}...")
urllib.request.urlretrieve(url, filename)
print("Download complete! File saved to your current directory.")