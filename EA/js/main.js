var makePost, likePost, deletePost, deletePost,
    nearest = (name, node) => {
        while (node.className.indexOf(name) == -1 && parent != null)
            node = node.parentElement;
        return node;
    }

window.onload = () => {

    const msg = document.getElementById("input"),
        posts_container = document.getElementById("posts"),
        url = 'http://localhost:5000/api/post';

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
                            <p>${element.Message}</p>
                        </div>
                        <div class="actions_aria">
                            <div>
                                <button class="like" onclick="likePost('${element.Id}')">inc</button>
                                <span>${element.Likes}</span>
                                <button class="dislike" onclick="dislikePost('${element.Id}')">dec</button>
                            </div>
                        </div>
                        <i class="icon_close" onclick="deletePost('${element.Id}')"></i>
                    </div>
                `
        });
    }

    makePost = () => {
        fetch(url, {
            headers: { 'Content-Type': 'application/json' },
            method: "POST",
            body: JSON.stringify({ message: msg.value })
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