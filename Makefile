# Compilador a utilizar
CXX = g++

# Flags de compilación
CXXFLAGS =  -O2

# Archivos fuente
SOURCES = kdTree.cc nearestNeighbour.cc

# Nombre del archivo de salida
TARGET_TEST = TestKDTree

# Regla por defecto
all: $(TARGET_TEST) generadorKdTree queryKdTree

# Regla para compilar el TARGET
$(TARGET_TEST): $(SOURCES)
	$(CXX) TestKdTree.cc $(SOURCES) -lgtest -lpthread -pedantic $(CXXFLAGS) -o $(TARGET_TEST)

generadorKdTree: $(SOURCES) generadorKdTree.cc
	$(CXX) generadorKdTree.cc $(SOURCES) $(CXXFLAGS) -o generadorKdTree

queryKdTree: queryKdTree.cc $(SOURCES)
	$(CXX) queryKdTree.cc $(SOURCES) $(CXXFLAGS) -o queryKdTree

# Regla para limpiar archivos generados
clean:
	rm -f $(TARGET_TEST) queryKdTree generadorKdTree victor_experimental
