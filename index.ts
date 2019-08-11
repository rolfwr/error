
// These import statements makes Parcel bundle up the CSS and inject it into
// the index.html file.
import 'reveal.js/css/reveal.css';
import 'reveal.js/css/theme/moon.css';
import 'reveal.js/lib/css/monokai.css'; 

const Reveal = require('reveal.js/js/reveal.js');
Reveal.initialize({
    history: true
});
