document.addEventListener('DOMContentLoaded', function () {
    // Fill the year in the footer
    const yearSpan = document.getElementById('currentYear');
    if (yearSpan) {
        yearSpan.textContent = new Date().getFullYear();
    }

    // Load the latest GitHub repository for the featured project
    const featuredProjectContainer = document.getElementById('featured-project');
    const githubUsername = 'Rodrigo-Frutuoso';

    if (featuredProjectContainer) {
        fetch(`https://api.github.com/users/${githubUsername}/repos?sort=updated&per_page=1`)
            .then(response => response.json())
            .then(repos => {
                if (repos.length > 0) {
                    const repo = repos[0]; // Get the most recently updated repository
                    featuredProjectContainer.innerHTML = `
                        <div class="card-body">
                            <h3 class="card-title">${repo.name}</h3>
                            <p class="card-text">${repo.description || 'No description available.'}</p>
                            <a href="${repo.html_url}" class="btn btn-primary" target="_blank" rel="noopener noreferrer">View on GitHub</a>
                        </div>
                    `;
                } else {
                    featuredProjectContainer.innerHTML = '<p class="text-muted">No repositories found.</p>';
                }
            })
            .catch(error => {
                console.error('Error fetching the latest repository:', error);
                featuredProjectContainer.innerHTML = '<p class="text-danger">Error loading the featured project. Please try again later.</p>';
            });
    }

    // Load GitHub repositories
    const reposContainer = document.getElementById('repos-container');

    if (reposContainer) {
        console.log('Fetching repositories for user:', githubUsername);

        fetch(`https://api.github.com/users/${githubUsername}/repos`)
            .then(response => {
                console.log('Server response:', response);
                return response.json();
            })
            .then(repos => {
                console.log('Repositories received:', repos);

                if (Array.isArray(repos) && repos.length > 0) {
                    // Sort by most recently updated
                    repos
                        .sort((a, b) => new Date(b.updated_at) - new Date(a.updated_at))
                        .forEach(repo => {
                            const repoCard = document.createElement('div');
                            repoCard.className = 'col-md-4 mb-4';
                            repoCard.innerHTML = `
                                <div class="card h-100 shadow-sm">
                                    <div class="card-body d-flex flex-column">
                                        <h5 class="card-title">${repo.name}</h5>
                                        <p class="card-text">${repo.description || 'No description available.'}</p>
                                        <a href="${repo.html_url}" class="btn btn-primary mt-auto" target="_blank" rel="noopener noreferrer">View on GitHub</a>
                                    </div>
                                </div>
                            `;
                            reposContainer.appendChild(repoCard);
                        });
                } else {
                    reposContainer.innerHTML = '<p class="text-muted">No repositories found.</p>';
                }
            })
            .catch(error => {
                console.error('Error fetching repositories:', error);
                reposContainer.innerHTML = '<p class="text-danger">Error loading repositories. Please try again later.</p>';
            });
    }
});
