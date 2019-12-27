var makePost, likePost, deletePost, deletePost,
    nearest = (name, node) => {
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
    var items = document.querySelectorAll('.data .item b');
    getRecordsAsync(api + ":3000/preferences")
        .then(path => path.forEach(element => {
            if (element.current != undefined) {
                current = element.current;
                document.querySelector('#wall .heading span').innerHTML = current;
                return;
            }
            
            if (element.name == current) {
                items[0].innerHTML = element.light;
                items[1].innerHTML = element.temperature;
                items[2].innerHTML = element.water;
            }
            M.updateTextFields();
            var selElems = document.querySelectorAll('select'),
                selInstances = M.FormSelect.init(selElems);
        }));

    var navElems = document.querySelectorAll('.sidenav')
        navOptions = {
            "edge": "right"
        },
        instances = M.Sidenav.init(navElems, navOptions);
});