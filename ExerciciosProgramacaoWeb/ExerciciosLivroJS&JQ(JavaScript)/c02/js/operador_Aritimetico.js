/*
Usando operadores aritiméticos
*/

var subtotal = (13 +1) * 5;
var shipping = 0.5 * (13 + 1);
var total = subtotal + shipping;

var elsub = document.getElementById('subtotal');
elsub.textContent = subtotal;

var elShip = document.getElementById('shipping');
elShip.textContent = shipping;

var elTotal = document.getElementById('total');
elTotal.textContent = total;