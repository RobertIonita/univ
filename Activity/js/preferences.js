const API = "http://" + window.location.hostname;

var updatePreferences,
    likePost,
    deletePreference,
    nearest = (name, node) => {
        while (node.className.indexOf(name) == -1 && parent != null)
            node = node.parentElement;
        return node;
    },
    updateCurrentAsync = (record) => {
        data = {
            "current": record.name,
            "currentId": record.id,
            "light": record.light,
            "temperature": record.temperature,
            "water": record.water
        }
        fetch(API + ':3000/preferences/0', {
            headers: { "Content-type": "application/json" },
            method: 'PATCH',
            body: JSON.stringify(data)
        })
            .then(response => response.json())
            .then(json => console.log(json))
    }

async function getRecordsAsync(url) {
    let response = await fetch(url),
        data = await response.json()
    return data;
}

document.addEventListener('DOMContentLoaded', function () {

    var input = document.querySelector('.input-field input');


    deletePreference = (id) => {
        fetch(API + ':3000/preferences/' + id, { method: 'DELETE' });
        location.reload();
    };
    getRecordsAsync(API + ":3000/preferences")
        .then(path => {
            M.updateTextFields();
        });
    updatePreferences = () => {
        currentId = getRecordsAsync(API + ':3000/preferences/0')
            .then(data => {
                var record = new Object();
                record = {
                    "teams": Number(input.value)
                }
                fetch(API + ':3000/preferences/' + data.currentId, {
                    headers: { 'Content-Type': 'application/json' },
                    method: "PATCH",
                    body: JSON.stringify(record)
                })
            })
    }

    var navElems = document.querySelectorAll('.sidenav'),
        navOptions = {
            "edge": "right"
        };
        M.Sidenav.init(navElems, navOptions);

});