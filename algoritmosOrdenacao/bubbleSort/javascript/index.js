// EXERCICIO 0
//1. Qual a diferença entre malloc e calloc?
// A função malloc apenas aloca, separa, a quantidade de memoria slicitada e retorna
// um ponteiro para o inicio daquela região da memoria
// A func calloc, por outro lado, além de separar a quantidade de memoria solicitada, ela
// já inicializa todas as posições com 0.

//2.Qual a diferença entre atribuição implicita e explicita?
// atribuição impplicita ex: byte valor1 = 10; byte valor2 = 20; long total = valor1 + valor2;
// atribuição explicita ex: long valor = 3000; int a = (int)valor;

//3. Qual a diferença entre heap e stack?
// O Heap, ou área de alocação dinâmica, é um espaço reservado para variáveis e dados criados durante a execução do programa (runtime). Vamos dizer que o Heap é a memória global do programa.
// Já a pilha de funções (stack) é uma área da memória que aloca dados/variáveis  ou ponteiros quando uma função é chamada e desalocada quando a função termina. Podemos dizer então que representa a memória local àquela função.
// 4. Var1 alocou memória onde armazenou o valor lá. Var2  aponta para endereço de v1. v3 aonta pro valor

function getRandom(n) {
  vectorArray = [];
  for (let i = 0; i < n; i++) {
    vectorArray.push(Math.floor(Math.random() * 10));
  }
  return vectorArray;
}

let bubbleSort = (inputArr) => {
  let len = inputArr.length; //n
  for (let i = 0; i < len; i++) {
    for (let j = 0; j < len; j++) {
      if (inputArr[j] > inputArr[j + 1]) {
        let tmp = inputArr[j];
        inputArr[j] = inputArr[j + 1];
        inputArr[j + 1] = tmp;
      }
    }
  }
  return inputArr;
};

inputArr = [5, 4, 3, 2, 1];
inputArr10000 = getRandom(10000);
console.log(inputArr10000);
console.log("bubbleSort", bubbleSort(inputArr));
// compexidade de espaço = O(n) - 4+n - estou pegando o mesmo array e reorganizando + 4 variaveis
// complexidade de tempo = O(n^2)
// No Big O, Bubble sort consiste em percorrer uma lista e ir trocando as posições dos elementos com o objetivo de deixar a lista
//ordenada, ou seja, de qualquer forma será necessario percorrer a lista inteira, pelo menos uma vez.

// Melhor caso O(n):
// O melhor caso do Bubble Sort ocorre quando o vetor está ordenado, pois o laço será executado uma única vez, quando i = 1.
// Dessa forma, a comparação será realizada n - 1 vezes. Portanto, a complexidade do Bubble Sort no melhor caso é O(n).

// Pior caso O(n^2):
// Bubblesort tem o seu pior caso quando a lista está em ordem reversa, nesse caso, no loop inicial o item que estava no posição 0
// terminará na posição n-1.
///////////////////////////////////////////////////////////////////////////////////////

// inserindo elementos no array como cartas num baralho
function insertionSort(inputArr) {
  let n = inputArr.length;
  for (let i = 1; i < n; i++) {
    // Escolhendo o elemento a ser inserido
    let current = inputArr[i];
    // o ultimo elemento da nossa sublista ordenada

    let j = i - 1;
    while (j > -1 && current < inputArr[j]) {
      inputArr[j + 1] = inputArr[j];
      j--;
    }
    inputArr[j + 1] = current;
  }
  return inputArr;
}

console.log("insertionSort", insertionSort(inputArr));

// complexidade de espaço(memoria) - O(n)
// complexidade de tempo(processos) - O(n^2)

// Note que o tempo de execução é dado pela soma dos passos de cada iteração. Essa soma pode ser representada por 1+2+3+…(n−1), ou seja,
// uma Progressão Aritmética Finita (PA) com a1=1 e an=(n−1) e razão r=1. A soma dos termos de uma PA é dada por: (a1+an)∗n/2.
// Então, temos que o tempo de execução do algoritmo é dado por (1+(n−1))∗n/2=(n2)/2. Aplicando as diretrizes de simplificação,
// o Insertion Sort é Θ(n2).

// PIOR caso - O pior caso do Insertion Sort é um array ordenado em ordem reversa, pois toda tentativa de inserção ordenada deve percorrer o array todo à esquerda trocando os elementos até encaixar o atual na primeira posição.
// MELHOR caso - lista em ordem crescente
// No melhor caso, este algoritmo é O(n). Isto ocorre quando o array já está ordenado. Deste maneira, a inserção ordenada de cada elemento
// tem custo O(1), pois todos já estão em suas devidas posições. Como a inserção ordenada é executada n vezes, o custo total é O(n)

// VANTAGEM: O Insertion Sort é estável porque mantém a ordem relativa dos valores iguais.
// Tem melhor desempenho que o selectionSort. consome pouca memoria no disco

// DESVANTAGEM: devido ao seu método de comparação, leva muito tempo para ordenar uma grande quantidade de números.
///////////////////////////////////////////////////////////////////

//Seleciona o menor elemento do array e coloca no inicio
function selectionSort(inputArr) {
  let n = inputArr.length;

  for (let i = 0; i < n; i++) {
    // procurando o menor elemento da lista
    let min = i;
    for (let j = i + 1; j < n; j++) {
      if (inputArr[j] < inputArr[min]) {
        min = j;
      }
    }
    if (min != i) {
      // trocando o menor elemento na menor posição diponível
      let tmp = inputArr[i];
      inputArr[i] = inputArr[min];
      inputArr[min] = tmp;
    }
  }
  return inputArr;
}

console.log("selectionSort", selectionSort(inputArr));
// Complexidade Espacial O(n)
// Complexidade Temporal O(n^2)
// Melhor caso O(n^2): independente da ordem do array o algoritmo sempre vai percorrer todo o array
// Pior caso O(n^2) -

// ex: inputArr = [3, 7, 4, 2, 9, 5]; 1 + 5*(n-1) + X*(n-1)
// n + (n-1) + (n-2) + ... + 2 = (n+2)(n-1)/2
// 1 + 5*(n-1) + (n^2+n-2)/2 => (1-1-5) + (5n +n/2) + n^2/2 = O(n^2)

//Desvantagens
// Não é uma estratégia eficiente para ordenar dados, pois é lento em vetores grandes, instavel
// https://joaoarthurbm.github.io/eda/posts/selection-sort/
