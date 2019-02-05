// UMA FUNÇÃO BÁSICA

var msg = 'Sign up to receive our newsoetter for 10% off!';
function updateMessage() {
  var el = document.getElementById('message')
  el.textContent = msg;
}
updateMessage();