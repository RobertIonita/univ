var makePost, likePost, deletePost, deletePost,
    nearest = (name, node) => {
        while (node.className.indexOf(name) == -1 && parent != null)
            node = node.parentElement;
        return node;
    }

document.addEventListener('DOMContentLoaded', function () {

    const url = 'http://localhost:3000/lightSensor';

    async function getRecordsAsync() {
        let response = await fetch(url),
            data = await response.json()
        return data;
    }
    // getRecordsAsync();

    makePost = (e) => {
        var data = new Object();
        data = {
            "firstName": "Lk",
            "lastName": "fwewfe",
            "email": "meesfark.ff@example.com",
            "age": 121,
            "companyId": "1"
        }
        fetch(url, {
            headers: { 'Content-Type': 'application/json' },
            method: "POST",
            body: JSON.stringify(data)
        })
    }
    deletePost = (id) => {
        fetch(url + '/' + id, { method: 'DELETE' })
        posts_container.removeChild(nearest("post", event.target));
    }

    var elems = document.querySelectorAll('.sidenav'),
        options = {
            "edge": "right"
        },
        instances = M.Sidenav.init(elems, options);

});