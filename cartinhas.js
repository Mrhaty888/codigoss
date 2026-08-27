const cartas = [
  "O Louco",
  "O Mago",
  "A Sacerdotisa",
  "A Imperatriz",
  "O Imperador",
  "O Papa",
  "Os Enamorados",
  "O Carro",
  "A Justiça",
  "O Eremita",
  "A Roda da Fortuna",
  "A Força",
  "O Enforcado",
  "A Morte",
  "A Temperança",
  "O Diabo",
  "A Torre",
  "A Estrela",
  "A Lua",
  "O Sol",
  "O Julgamento",
  "O Mundo"
];

const cores = ["#891abc", "#6b2ecc", "#511863", "#9b59b6", "#e67e22", "#801176"];

const elementocarta = document.getElementById("frase");
const botao2 = document.getElementById("botao");

function gerarcarta(){

    const indicecarta = Math.floor(Math.random() * cartas.length);
    elementocarta.textContent = cartas[indicecarta];

    const indicecor = Math.floor(Math.random() * cores.length);
    document.body.style.backgroundColor = cores[indicecor];
}

botao2.addEventListener("click",gerarcarta);