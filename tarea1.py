 # Estructura de Datos 2023-1
# Juan David Niño Galvis

def countValid(count):
    if count >= (len(list))/2:
        return True

# Punto 1
def verificarDiagonales(mat):
    count = 0
    n = len(mat)
    i = 1
    while i <= n:
        if mat[i-1][i-1] == mat[i-1][-i]:
            count += 1
        else:
            return False
    countValid(count)

# Punto 2

def esCapicua(list):
    isCapicua = False
    i = 0
    while i <= len(list) and i<(len(list)/2):
        if (list[i] == list[len(list)-i-1]):
            isCapicua = True
        i = i+1
    return isCapicua

# Punto 3-A

def diferenciaListas(array1,array2):
    commonList = array1
    deleted, i = [], 0
    while i <= len(array1)-1:
        if array1[i] in array2 and array1[i] not in deleted:
            deleted.append(commonList.pop(i))
        else:
            i += 1
    return commonList

# Punto 4

def esPrimo(num):
    if num < 2:
        return False
    for i in range(2, num):
        if num % i == 0:
            return False
    return True

def sumaDigitos(num):
    suma = 0
    while num > 0:
        suma += num % 10
        num //= 10
    return suma

def mostrarPrimos(n):
    for num in range(1, n+1):
        if esPrimo(num):
            suma = sumaDigitos(num)
            if esPrimo(suma):
                print(num) 


#Punto 5

def sumarValoresMatriz(disp, position):
    sumatoria = 0
    i = 0
    while i <= len(position)-1:
        key = position[i][0]
        if key in disp:
            array = disp[key]
            j = 0
            while j <= len(array)-1:
                if position[i][1] == array[j][0]:
                    sumatoria += array[j][1]
                j += 1
        i += 1
    return sumatoria