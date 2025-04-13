document.addEventListener("DOMContentLoaded", loadInventory);

function loadInventory() {
  fetch("/api/inventory")
    .then(response => response.json())
    .then(data => {
      const tbody = document.querySelector("#inventory tbody");
      data.forEach(item => {
        const row = `<tr>
          <td>${item.id}</td>
          <td>${item.name}</td>
          <td>${item.description}</td>
          <td>${item.quantity}</td>
        </tr>`;
        tbody.innerHTML += row;
      });
    })
    .catch(err => console.error("Failed to fetch inventory", err));
}