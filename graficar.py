# graficar.py
import pandas as pd
import matplotlib.pyplot as plt

# Leer datos
df = pd.read_csv('tiempos.csv')

# Crear gráfica
plt.figure(figsize=(6, 4))
plt.bar(df['Parser'], df['TiempoPromedio'], color=['skyblue', 'salmon'])
plt.title('Comparación de Tiempo Promedio (Bison vs CYK)')
plt.ylabel('Tiempo (segundos)')
plt.grid(axis='y', linestyle='--', alpha=0.7)

# Guardar y mostrar
plt.tight_layout()
plt.savefig('comparacion_tiempos.png')
plt.show()
