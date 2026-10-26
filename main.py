# import csv
# import subprocess
# import sys
# from pathlib import Path

# import matplotlib.pyplot as plt


# def read_metadata(csv_path: Path) -> dict[str, float]:
#     """Read metadata lines beginning with '#' from the CSV."""

#     metadata: dict[str, float] = {}

#     with csv_path.open("r", encoding="utf-8") as file:
#         for line in file:
#             if not line.startswith("#"):
#                 break

#             text = line[1:].strip()

#             if "=" not in text:
#                 continue

#             key, value = text.split("=", maxsplit=1)
#             metadata[key] = float(value)

#     return metadata


# def read_memberships(
#     csv_path: Path,
# ) -> dict[str, list[float]]:
#     """Read all membership values exported by the C controller."""

#     columns = [
#         "x",
#         "salary_poor",
#         "salary_good",
#         "salary_excellent",
#         "debts_small",
#         "debts_large",
#         "risk_low",
#         "risk_normal",
#         "risk_high",
#         "clipped_low",
#         "clipped_normal",
#         "clipped_high",
#         "aggregated",
#     ]

#     data: dict[str, list[float]] = {
#         column: [] for column in columns
#     }

#     with csv_path.open("r", encoding="utf-8") as file:
#         rows = (
#             line
#             for line in file
#             if not line.startswith("#")
#         )

#         reader = csv.DictReader(rows)

#         if reader.fieldnames is None:
#             raise ValueError("CSV file has no column header.")

#         missing_columns = [
#             column
#             for column in columns
#             if column not in reader.fieldnames
#         ]

#         if missing_columns:
#             raise ValueError(
#                 "CSV is missing columns: "
#                 + ", ".join(missing_columns)
#             )

#         for row in reader:
#             for column in columns:
#                 data[column].append(float(row[column]))

#     return data


# def open_image(output_path: Path) -> None:
#     """Open the generated PNG using the Windows default viewer."""

#     try:
#         result = subprocess.run(
#             ["wslpath", "-w", str(output_path)],
#             capture_output=True,
#             text=True,
#             check=True,
#         )

#         windows_path = result.stdout.strip()

#         subprocess.run(
#             ["cmd.exe", "/C", "start", "", windows_path],
#             check=False,
#         )

#     except (FileNotFoundError, subprocess.CalledProcessError):
#         print(
#             "Could not open the Windows image viewer automatically."
#         )

#         print(
#             f"Open the image manually: {output_path}"
#         )


# def render_memberships(
#     data: dict[str, list[float]],
#     metadata: dict[str, float],
# ) -> None:
#     """Render salary, debt, and Mamdani output memberships."""

#     salary = metadata.get("salary", 0.0)
#     debts = metadata.get("debts", 0.0)
#     risk = metadata.get("risk", 0.0)

#     rule_low = metadata.get("rule_low", 0.0)
#     rule_normal = metadata.get("rule_normal", 0.0)
#     rule_high = metadata.get("rule_high", 0.0)

#     x = data["x"]

#     figure, axes = plt.subplots(
#         nrows=2,
#         ncols=2,
#         figsize=(14, 10),
#     )

#     salary_axis = axes[0][0]
#     debts_axis = axes[0][1]
#     original_risk_axis = axes[1][0]
#     aggregated_axis = axes[1][1]

#     # ---------------------------------------------------------
#     # Salary memberships
#     # ---------------------------------------------------------

#     salary_axis.plot(
#         x,
#         data["salary_poor"],
#         label="Poor",
#     )

#     salary_axis.plot(
#         x,
#         data["salary_good"],
#         label="Good",
#     )

#     salary_axis.plot(
#         x,
#         data["salary_excellent"],
#         label="Excellent",
#     )

#     salary_axis.axvline(
#         salary,
#         color="black",
#         linestyle="--",
#         label=f"Salary input: RM{salary:.1f}K",
#     )

#     salary_axis.set_title(
#         "Salary Membership Functions"
#     )

#     salary_axis.set_xlabel(
#         "Annual salary (RM thousands)"
#     )

#     salary_axis.set_ylabel(
#         "Membership degree"
#     )

#     salary_axis.set_xlim(0, 100)
#     salary_axis.set_ylim(0, 1.05)
#     salary_axis.grid(True)
#     salary_axis.legend()

#     # ---------------------------------------------------------
#     # Debt memberships
#     # ---------------------------------------------------------

#     debts_axis.plot(
#         x,
#         data["debts_small"],
#         label="Small",
#     )

#     debts_axis.plot(
#         x,
#         data["debts_large"],
#         label="Large",
#     )

#     debts_axis.axvline(
#         debts,
#         color="black",
#         linestyle="--",
#         label=f"Debt input: RM{debts:.1f}K",
#     )

#     debts_axis.set_title(
#         "Debt Membership Functions"
#     )

#     debts_axis.set_xlabel(
#         "Debt amount (RM thousands)"
#     )

#     debts_axis.set_ylabel(
#         "Membership degree"
#     )

#     debts_axis.set_xlim(0, 100)
#     debts_axis.set_ylim(0, 1.05)
#     debts_axis.grid(True)
#     debts_axis.legend()

#     # ---------------------------------------------------------
#     # Original risk memberships
#     # ---------------------------------------------------------

#     original_risk_axis.plot(
#         x,
#         data["risk_low"],
#         label="Low",
#     )

#     original_risk_axis.plot(
#         x,
#         data["risk_normal"],
#         label="Normal",
#     )

#     original_risk_axis.plot(
#         x,
#         data["risk_high"],
#         label="High",
#     )

#     original_risk_axis.set_title(
#         "Original Risk Membership Functions"
#     )

#     original_risk_axis.set_xlabel(
#         "Risk (%)"
#     )

#     original_risk_axis.set_ylabel(
#         "Membership degree"
#     )

#     original_risk_axis.set_xlim(0, 100)
#     original_risk_axis.set_ylim(0, 1.05)
#     original_risk_axis.grid(True)
#     original_risk_axis.legend()

#     # ---------------------------------------------------------
#     # Clipped and aggregated Mamdani output
#     # ---------------------------------------------------------

#     aggregated_axis.plot(
#         x,
#         data["clipped_low"],
#         label=f"Clipped low ({rule_low:.2f})",
#     )

#     aggregated_axis.plot(
#         x,
#         data["clipped_normal"],
#         label=f"Clipped normal ({rule_normal:.2f})",
#     )

#     aggregated_axis.plot(
#         x,
#         data["clipped_high"],
#         label=f"Clipped high ({rule_high:.2f})",
#     )

#     aggregated_axis.fill_between(
#         x,
#         data["aggregated"],
#         alpha=0.3,
#         label="Aggregated output",
#     )

#     aggregated_axis.plot(
#         x,
#         data["aggregated"],
#         color="black",
#         linewidth=2,
#     )

#     aggregated_axis.axvline(
#         risk,
#         color="red",
#         linestyle="--",
#         linewidth=2,
#         label=f"Centroid: {risk:.2f}%",
#     )

#     aggregated_axis.set_title(
#         "Mamdani Aggregation and Defuzzification"
#     )

#     aggregated_axis.set_xlabel(
#         "Risk (%)"
#     )

#     aggregated_axis.set_ylabel(
#         "Membership degree"
#     )

#     aggregated_axis.set_xlim(0, 100)
#     aggregated_axis.set_ylim(0, 1.05)
#     aggregated_axis.grid(True)
#     aggregated_axis.legend()

#     figure.suptitle(
#         "Mamdani Fuzzy Risk Assessment",
#         fontsize=16,
#     )

#     figure.tight_layout(
#         rect=(0.0, 0.0, 1.0, 0.96)
#     )

#     output_path = Path(
#         "mamdani_membership_functions.png"
#     ).resolve()

#     figure.savefig(
#         output_path,
#         dpi=150,
#         bbox_inches="tight",
#     )

#     plt.close(figure)

#     print(f"Graph saved to: {output_path}")

#     open_image(output_path)


# def main() -> int:
#     if len(sys.argv) != 2:
#         print(
#             f"Usage: {sys.argv[0]} <membership_csv>",
#             file=sys.stderr,
#         )

#         return 1

#     csv_path = Path(sys.argv[1])

#     if not csv_path.is_file():
#         print(
#             f"Error: file does not exist: {csv_path}",
#             file=sys.stderr,
#         )

#         return 1

#     try:
#         metadata = read_metadata(csv_path)
#         memberships = read_memberships(csv_path)

#         render_memberships(
#             memberships,
#             metadata,
#         )

#     except (ValueError, KeyError) as error:
#         print(
#             f"Error reading membership data: {error}",
#             file=sys.stderr,
#         )

#         return 1

#     return 0


# if __name__ == "__main__":
#     raise SystemExit(main())

