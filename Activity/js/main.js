var nearest = (name, node) => {
    while (node.className.indexOf(name) == -1 && parent != null)
        node = node.parentElement;
    return node;
}

async function getRecordsAsync(url) {
    let response = await fetch(url),
        data = await response.json()
    return data;
}

document.addEventListener('DOMContentLoaded', function () {
    const api = "http://" + window.location.hostname;
    var items = document.querySelectorAll('.data .item b'),
        current_team = document.querySelector('.current_team b'),
        current_time = document.querySelector('.current_time b'),
        players = document.querySelectorAll('.players'),
        count = 4,
        time = 30,
        names = [],
        current = 'alb',
        current_team_nr = 0,
        scores = [0, 0, 0, 0],
        word = document.querySelector('.modal .word'),
        word_type = document.querySelector('.modal .word_type'),
        updateMap = (names) => {
            current_team = current;
            for (let i = 0; i < players.length; i++)
                players[i].className = 'players d_fl a_c j_c';
            for (let i = 0; i < count; i++)
                players[scores[i]].className += ' ' + names[i];
        }
    getRecordsAsync(api + ":3000/data/0")
        .then(data => {
            count = data.teams;
            time = data.time;
            names = data.names;
            scores = data.scores;
            current = data.current;
            current_time.innerHTML = time + 's';
            current_team.innerHTML = current;
            updateMap(names);
        });
    getRecordsAsync(api + ":3000/words/1")
        .then(data => {
            word.innerHTML = data.word;
            word_type.innerHTML = data.type;
        });

    var stepForward = function () {
        var timerInterval = setInterval(timer, 1000);
        function timer() {
            current_time.innerHTML = --time + 's';
        }
        setTimeout(() => {
            clearInterval(timerInterval);
            modalInstances[1].open();
            time = 30;
            current_time.innerHTML = time + 's';
        }, 5000);
    }
    var correct_answer = document.querySelector('.correct_answer'),
        wrong_answer = document.querySelector('.wrong_answer'),
        start_game = document.querySelector('.start_game'),
        nextStep = function () {
            modalInstances[1].close();
            current = names[(current_team_nr + 1) % count]
            record = {
                "id": "0",
                "teams": current_team_nr,
                "time": time,
                "names": names,
                "scores": scores,
                "current": current
            }
            fetch(api + ':3000/data/0', {
                headers: { 'Content-Type': 'application/json' },
                method: "PATCH",
                body: JSON.stringify(record)
            })
        },
        moveTeam = function () {
            nextStep();
            updateMap(names);
            current_team_nr = current;
        },
        skipTeam = function () {
            nextStep();
            current_team_nr = current;
        }
    start_game.onclick = stepForward;
    correct_answer.onclick = moveTeam;
    wrong_answer.onclick = skipTeam;

    var navElems = document.querySelectorAll('.sidenav'),
        navOptions = {
            "edge": "right"
        },
        navInstances = M.Sidenav.init(navElems, navOptions),
        modalOptions = {
            "dismissible": false
        }
    modalElems = document.querySelectorAll('.modal'),
        modalInstances = M.Modal.init(modalElems, modalOptions);
});