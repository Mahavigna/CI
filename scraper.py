import urllib.request

url = "https://github.com/billcary/uci_combined_cycle_power_plant/raw/refs/heads/master/data/Folds5x2_pp.xlsx"
# url = "https://archive.ics.uci.edu/ml/machine-learning-databases/00243/yacht_hydrodynamics.data"
# url = "https://archive.ics.uci.edu/ml/machine-learning-databases/00291/airfoil_self_noise.dat"
filename = "plant_test.xlsx"

print(f"Downloading {filename}...")
urllib.request.urlretrieve(url, filename)
print("Download complete! File saved to your current directory.")