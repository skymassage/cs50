document.addEventListener('DOMContentLoaded', function() {
    // Navbar highlight
    var url = window.location.href;
    var navElementId = url.split('/').pop().split('.')[0];
    var navElement = document.querySelector(`#${navElementId}`);
    navElement.classList.add('active');

    // Cat's greet
    document.querySelector('#greet').addEventListener('submit', function(event) {
        const audio = document.createElement('audio');
        audio.src = "static/meow.mp3";
        audio.play();
        event.preventDefault();
    });
});
