var hotel = {
  nome: 'Lys',
  quartos: 40,
  reservado: 15,
  disponiveis: function() {
    return this.quartos - this.reservado;
  }
};

var elNome = document.getElementById('hotelName');
elNome.textContent = hotel.nome;

var elQuartos = document.getElementById('rooms');
elQuartos.textContent = hotel.disponiveis();