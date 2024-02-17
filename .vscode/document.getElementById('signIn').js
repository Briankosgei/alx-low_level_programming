document.getElementById('signIn').addEventListener('click', function() {
  document.getElementById('registrationForm').classList.toggle('hidden');
});

document.getElementById('login').addEventListener('click', function() {
  document.getElementById('loginForm').classList.toggle('hidden');
});

document.getElementById('registerForm').addEventListener('submit', function(event) {
  event.preventDefault();
  var username = document.getElementById('username').value;
  var password = document.getElementById('password').value;
  // You can handle registration logic here, like sending data to a server
  console.log('Registered with Username: ' + username + ', Password: ' + password);
  // For demonstration, just hiding the registration form after submitting
  document.getElementById('registrationForm').classList.add('hidden');
});

document.getElementById('loginForm').addEventListener('submit', function(event) {
  event.preventDefault();
  var loginUsername = document.getElementById('loginUsername').value;
  var loginPassword = document.getElementById('loginPassword').value;
  // You can handle login logic here, like checking credentials with a server
  console.log('Logged in with Username: ' + loginUsername + ', Password: ' + loginPassword);
  // For demonstration, just hiding the login form after submitting
  document.getElementById('loginForm').classList.add('hidden');
});
