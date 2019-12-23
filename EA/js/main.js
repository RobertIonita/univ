var makePost, likePost, deletePost, deletePost,
    nearest = (name, node) => {
        while (node.className.indexOf(name) == -1 && parent != null)
            node = node.parentElement;
        return node;
    }

window.onload = () => {

    const form = document.querySelector("form"),
        posts_container = document.getElementById("posts"),
        url = 'http://localhost:3000/users';

    async function getRecordsAsync() {
        let response = await fetch(url),
            data = await response.json()
        return data;
    }
    getRecordsAsync()
        .then(data => renderPosts(data));
    var renderPosts = (records) => {
        posts_container.innerHTML = "";
        records.sort((a, b) => (a.Likes < b.Likes) ? 1 : -1);
        records.forEach(element => {
            posts_container.innerHTML += `
                    <div class="block post">
                        <div class="message_area">
                            <p>${element.firstName} ${element.lastName}</p>
                        </div>
                        <p>${element.age}</p>
                        <p>${element.email}</p>
                        <button onclick="deletePost('${element.id}')">Delete</button>
                    </div>
                `
        });
    }

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
    likePost = function (id) {
        fetch(url + '/like/' + id, { method: 'PUT' })
        let counter = nearest("actions_aria", event.target).querySelector("span");
        counter.innerHTML = Number(counter.innerHTML) + 1;
    }
    dislikePost = (id) => {
        fetch(url + '/dislike/' + id, { method: 'PUT' })
        let counter = nearest("actions_aria", event.target).querySelector("span");
        counter.innerHTML == "0" ? 0 : counter.innerHTML = Number(counter.innerHTML) - 1;
    }
    deletePost = (id) => {
        fetch(url + '/' + id, { method: 'DELETE' })
        posts_container.removeChild(nearest("post", event.target));
    }
}