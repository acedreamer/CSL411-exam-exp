(function() {
  function getPreferredTheme() {
    const saved = localStorage.getItem('theme');
    if (saved) return saved;
    return window.matchMedia('(prefers-color-scheme: dark)').matches ? 'dark' : 'light';
  }

  function applyTheme(theme) {
    document.documentElement.setAttribute('data-theme', theme);
    const btn = document.getElementById('theme-toggle-btn');
    if (btn) {
      const isDark = theme === 'dark';
      btn.innerHTML = `<span class="theme-icon">${isDark ? '🌙' : '☀️'}</span> <span>${isDark ? 'Dark' : 'Light'}</span>`;
      btn.setAttribute('aria-label', `Switch to ${isDark ? 'light' : 'dark'} mode`);
    }
  }

  // Set immediately to avoid flash of wrong theme
  const initialTheme = getPreferredTheme();
  document.documentElement.setAttribute('data-theme', initialTheme);

  // Initialize button when DOM is ready
  document.addEventListener('DOMContentLoaded', function() {
    let container = document.querySelector('.theme-toggle-wrapper');
    if (!container) {
      container = document.createElement('div');
      container.className = 'theme-toggle-wrapper';
      container.innerHTML = `<button id="theme-toggle-btn" class="theme-toggle-btn"></button>`;
      document.body.appendChild(container);
    }
    
    applyTheme(document.documentElement.getAttribute('data-theme') || initialTheme);

    const toggleBtn = document.getElementById('theme-toggle-btn');
    if (toggleBtn) {
      toggleBtn.addEventListener('click', function() {
        const current = document.documentElement.getAttribute('data-theme');
        const next = current === 'dark' ? 'light' : 'dark';
        localStorage.setItem('theme', next);
        applyTheme(next);
      });
    }

    // React to system changes if user hasn't explicitly set a preference
    window.matchMedia('(prefers-color-scheme: dark)').addEventListener('change', e => {
      if (!localStorage.getItem('theme')) {
        applyTheme(e.matches ? 'dark' : 'light');
      }
    });
  });
})();
