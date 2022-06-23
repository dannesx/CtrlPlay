// DESAFIO - Escreva uma função que retorne uma sequência de Fibonacci de tamanho X (informado pelo usuário). Esta sequência deve começar com o número 1. Adicionar os números em uma array. Imprima a array utilizando "console.log()"
var tamanho = parseInt(prompt("Qual o tamanho da sequência de Fibonacci?"))
function fib(x){
   var fibonacci = []

   for(let i = 0; i < x; i++){
      if(i == 0 || i == 1) fibonacci.push(1)
      if(i >= 2) {
         fibonacci.push(fibonacci[i-1] + fibonacci[i-2])
      }
   }

   return fibonacci
}

console.log("Entrada do usuário: " + fib(tamanho))
console.log(fib(0))
console.log(fib(1))
console.log(fib(2))
console.log(fib(6))
console.log(fib(10))
console.log(fib(20))