const API = "http://" + window.location.hostname;

var makePost, likePost,
    nearest = (name, node) => {
        while (node.className.indexOf(name) == -1 && parent != null)
            node = node.parentElement;
        return node;
    },

    deletePreference = (id) => {
        fetch(API + ':3000/preferences/' + id, { method: 'DELETE' })
    },
    updateCurrentAsync = (newPreference) => {
        data = {
            "current": newPreference
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
async function getKindAsync(url) {
    let response = await fetch(url),
        data = await response.json()
    return data;
}



document.addEventListener('DOMContentLoaded', function () {

    var select = document.querySelector("#kind"),
        inputs = document.querySelectorAll('.input-field input[required]'),
        selElems = document.querySelectorAll('select');
    let i = 0, current;
    var addIcon = (element, item) => {

        item.className = 'd_fl a_c j_sb';
        item.innerHTML = `
            <span>${item.innerHTML}</span>
            <i class="material-icons clickable" onclick="deletePreference('${element.id}')">delete</i>
        `
    }
    getKindAsync(API + ":3000/preferences")
        .then(path => {
            path.forEach(element => {
                if (element.current != undefined) {
                    current = element.current;
                    return;
                }

                select.innerHTML += `
                    <option value="${element.name}">${element.name}</option>
                `
                if (element.name == current) {
                    inputs[0].value = element.light;
                    inputs[1].value = element.temperature;
                    inputs[2].value = element.water;
                }
            });
            var selInstances = M.FormSelect.init(selElems);
            M.updateTextFields()
            let list = document.querySelectorAll(".dropdown-content span"),
                i = 0;
            path.forEach(element => {
                list[i].addEventListener("click", function () {
                    updateCurrentAsync(this.innerText.replace('\ndelete', ''));
                });
                if (element.name != current)
                    addIcon(element, list[i]);
                i++;
            })
        });
    makePost = () => {
        var data = new Object();
        inputs.forEach(element => {
            console.log(element)
        })
        data = {
            "time": "13:22:45",
            "value": 124,
            "set": 123
        }
        // fetch(url, {
        //     headers: { 'Content-Type': 'application/json' },
        //     method: "POST",
        //     body: JSON.stringify(data)
        // })
    }

    var navElems = document.querySelectorAll('.sidenav'),
        navOptions = {
            "edge": "right"
        },
        navInstances = M.Sidenav.init(navElems, navOptions);


});