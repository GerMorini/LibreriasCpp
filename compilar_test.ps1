# Funciones para imprimir texto en color
function Write-Color($message, $color) {
    $colorCodes = @{
        'Red' = '31'
        'Green' = '32'
        'Yellow' = '33'
        'Blue' = '34'
        'Magenta' = '35'
        'Cyan' = '36'
        'White' = '37'
    }
    $colorCode = $colorCodes[$color]
    Write-Output "`e[${colorCode}m$message`e[0m"
}

# Definir los nombres de los archivos
$sourceFile = "validacion.cpp"
$testFile = "validacion_test.cpp"
$outputExe = "exec/val_test.exe"

# Comando de compilación
$compileCommand = "g++ -Wall -g -o $outputExe $sourceFile $testFile"

# Compilar los archivos
Write-Color "Compilando $sourceFile y $testFile..." 'Yellow'
Invoke-Expression $compileCommand

# Verificar si la compilación fue exitosa
if ($LASTEXITCODE -eq 0) {
    Write-Color "Compilación exitosa." 'Green'

    # Ejecutar el archivo ejecutable
    Write-Color "Ejecutando $outputExe..." 'Cyan'
    . $outputExe
} else {
    Write-Color "Error en la compilación." 'Red'
}
