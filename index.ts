
// These import statements makes Parcel bundle up the CSS and inject it into
// the index.html file.
import 'reveal.js/css/reveal.css';
import 'reveal.js/css/theme/moon.css';
import 'reveal.js/lib/css/monokai.css'; 
import './styling.css';

const Reveal = require('reveal.js/js/reveal.js');

// Reveal.js plugin loading expects to find the Reveal instance here.
declare global {
    interface Window { Reveal: any; }
}

window.Reveal = Reveal;

Reveal.initialize({
    history: true,
    dependencies: [
        { src: 'highlight.js', async: true }
    ]
});
