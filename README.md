# Information Security – Assignment 2

Students: 23F-3010, 23F-3094

## Contents

### `Education_Portal/` – Learnspace (secure Flask web app)
A small education portal with signup/login, courses, enrollment, comments and a profile page.

Security controls:
- **Password storage:** salted hashes via `werkzeug.security`
- **SQL injection:** parameterized queries everywhere
- **XSS:** Jinja2 auto-escaping (no `|safe`), input length limits, `HttpOnly` session cookie, `nosniff` header
- **CSRF:** per-session random token checked on every POST (`secrets.compare_digest`), `SameSite=Lax` cookie, POST-only logout
- **Clickjacking:** `X-Frame-Options: DENY`
- **Session security:** session cleared and token rotated on login, 2-hour lifetime

Run it:
```bash
cd Education_Portal
python -m venv .venv
.venv/Scripts/pip install -r requirements.txt   # Windows
# source .venv/bin/activate && pip install -r requirements.txt   # Linux/macOS
python app.py
```
Open http://127.0.0.1:5000/signup to create an account. The database and secret key are created on first run.

### `stack.c` / `exploit.c` – Buffer overflow lab
- `stack.c` reads `badfile` and copies it into a 12-byte buffer with `strcpy` (deliberately unsafe).
- `exploit.c` generates `badfile`.

```bash
gcc -o exploit exploit.c && ./exploit
gcc -fno-stack-protector -z execstack -o stack stack.c && ./stack
```
