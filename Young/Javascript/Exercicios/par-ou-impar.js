//2 - Faça um script que, dado um número inteiro, informe se este é par ou ímpar
var numero = parseInt(prompt('Informe um número inteiro'))

if (numero % 2 == 0) {
	console.log(numero + ' é par')
} else {
	console.log(numero + ' é ímpar')
}