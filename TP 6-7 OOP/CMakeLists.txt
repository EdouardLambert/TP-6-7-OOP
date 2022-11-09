# CMakeList.txt : projet CMake pour TP 6-7 OOP, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.8)

# Ajoutez une source à l'exécutable de ce projet.
#add_executable (CMakeTarget "Exercice1/main.cpp")
#add_executable (CMakeTarget "Exercice2/main.cpp" "Exercice2/fraction.hpp" "Exercice2/fraction.cpp")
#add_executable (CMakeTarget "Exercice3/main.cpp")
add_executable (CMakeTarget "Exercice4/main.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()

# TODO: Ajoutez des tests et installez des cibles si nécessaire.
