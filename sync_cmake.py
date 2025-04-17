import shutil
import os

# Caminhos
base_file = "CMakeLists_main.txt"
dist_dir = os.path.join("dist")
dist_file = os.path.join(dist_dir, "CMakeLists.txt")

# Garante que a pasta dist existe
os.makedirs(dist_dir, exist_ok=True)

# Copia o arquivo base
try:
    shutil.copy(base_file, dist_file)
    print("✅ CMakeLists.txt copiado com sucesso para dist/")
except Exception as e:
    print(f"❌ Erro ao copiar CMakeLists.txt: {e}")
