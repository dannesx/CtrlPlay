# Importar biblioteca que irá sortear uma palavra
import random

# Sorteando uma palavra dentro da lista de palavras
palavras = ["Red", "Green", "Blue", "Yellow", "Purple", "White", "Black", "Brown", "Pink"]  
palavra = random.choice(palavras)

# Inicializando variáveis
chances = 7
palpites = []
fim = False

# Looping principal
while not fim:
	# 1. Imprimindo a palavra com espaços vazios
	print("Chances:", chances)
	for letra in palavra:
		if letra.lower() in palpites:
			print(letra, end=" ")
		else:
			print("_", end=" ")
	print("\n")

	# 2. Entrada de dados: Adicionando a letra na lista de palpites
	letra = input("Digite uma letra: ")
	palpites.append(letra.lower())

	# 3. Teste de Acerto: Se chegar à 0, o jogo acaba
	if letra.lower() not in palavra.lower():
		chances = chances - 1
		if chances == 0:
			break

	# 4. Teste de Fim de Jogo: Se as letras da palavra estiverem nos palpites, o jogo acaba
	for letra in palavra:
		if letra.lower() not in palpites:
			fim = False
			break
		else:
			fim = True

# Imprimindo a resposta
if fim:
	print("Parabéns, você ganhou! :D")
else:
	print("GAME OVER! :(")

print("A palavra era", palavra)