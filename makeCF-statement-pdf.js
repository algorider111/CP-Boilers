// Codeforces problem -> PDF showing only the rating in header
const script = document.createElement('script');
script.src = 'https://cdnjs.cloudflare.com/ajax/libs/html2pdf.js/0.10.1/html2pdf.bundle.min.js';
script.onload = () => {
  const element = document.querySelector('.problemindexholder');
  if (!element) {
    alert("Element with class 'problemindexholder' not found.");
    return;
  }

  // ---- Extract Title & Safe Filename ----
  const rawTitle = element.querySelector('.title')?.innerText || document.title || 'problem';
  const titleParts = rawTitle.split('. ');
  const cleanTitle = titleParts.length > 1 ? titleParts[1] : rawTitle;
  const safeFilename = cleanTitle.replace(/[<>:"/\\|?*\x00-\x1F]/g, '').trim() + '.pdf';

  // ---- Initialize links ----
  let problemLink = window.location.href;
  let submitLink = window.location.href;
  let submissionsLink = window.location.href;

  try {
    const urlObj = new URL(window.location.href);
    const pathParts = urlObj.pathname.split('/').filter(Boolean);
    if (pathParts[0] === 'contest' && pathParts.length >= 3) {
      const contestId = pathParts[1];
      const problemId = pathParts[2];
      problemLink = `https://codeforces.com/contest/${contestId}/problem/${problemId}`;
      submitLink = `https://codeforces.com/contest/${contestId}/submit/${problemId}`;
      submissionsLink = `https://codeforces.com/contest/${contestId}/status/${problemId}`;
    }
  } catch (e) {
    console.warn('URL parsing failed:', e);
  }

  // ---- Extract problem rating ----
  const ratingText = element.querySelector('.problem-rating')?.innerText.trim() || '';

  // ---- Clone problem statement ----
  const clone = element.cloneNode(true);
  clone.querySelectorAll('pre, code').forEach(n => {
    n.style.whiteSpace = 'pre-wrap';
    n.style.wordBreak = 'break-word';
  });

  // ---- Styles ----
  const style = document.createElement('style');
  style.innerHTML = `
    .pdf-root { font-family: 'Inter', 'Helvetica', Arial, sans-serif; color:#111; line-height:1.35; }
    .pdf-header { display:flex; justify-content:space-between; align-items:center; margin-bottom:16px; border-bottom:2px solid #0b5ed7; padding-bottom:12px; }
    .pdf-title { font-size:24px; font-weight:700; margin:0; }
    .pdf-rating { font-size:16px; font-weight:600; background:#0b5ed7; color:white; padding:4px 8px; border-radius:6px; }
    .pdf-content { font-size:14px; color:#111; }
    pre, code { font-family: 'SFMono-Regular', Menlo, Monaco, 'Roboto Mono', monospace; font-size:12.5px; background:#f3f4f6; padding:8px; border-radius:6px; overflow:auto; }
    img { max-width:100%; height:auto; display:block; margin:8px 0; }
    .pdf-footer { text-align:center; font-size:11px; color:#666; padding-top:10px; border-top:1px solid #eee; margin-top:18px; }
  `;

  const fontLink = document.createElement('link');
  fontLink.href = 'https://fonts.googleapis.com/css2?family=Inter:wght@300;400;600;700&display=swap';
  fontLink.rel = 'stylesheet';

  // ---- Header ----
  const header = document.createElement('div');
  header.className = 'pdf-header';
  header.innerHTML = `
    <h1 class="pdf-title">${cleanTitle}</h1>
    ${ratingText ? `<div class="pdf-rating">${ratingText}</div>` : ''}
  `;

  // ---- Footer ----
  const footerNote = document.createElement('div');
  footerNote.className = 'pdf-footer';
  footerNote.innerHTML = `Generated from <a href="${problemLink}">${problemLink}</a>`;

  // ---- Wrap everything ----
  const tempContainer = document.createElement('div');
  tempContainer.className = 'pdf-root';
  tempContainer.style.background = '#fff';
  tempContainer.style.padding = '24px';
  tempContainer.style.boxSizing = 'border-box';
  tempContainer.style.maxWidth = '840px';
  tempContainer.style.margin = '0 auto';
  tempContainer.appendChild(fontLink);
  tempContainer.appendChild(style);
  tempContainer.appendChild(header);
  tempContainer.appendChild(clone);
  tempContainer.appendChild(footerNote);
  document.body.appendChild(tempContainer);

  // ---- Export PDF ----
  html2pdf().set({
    margin: [10, 12, 18, 12],
    filename: safeFilename,
    image: { type: 'jpeg', quality: 0.98 },
    html2canvas: { scale: 2, useCORS: true, scrollY: 0 },
    jsPDF: { unit: 'mm', format: 'a4', orientation: 'portrait' },
    pagebreak: { mode: ['css', 'legacy'] }
  }).from(tempContainer).toPdf().get('pdf').then(pdf => {
    const totalPages = pdf.internal.getNumberOfPages();
    const pageWidth = pdf.internal.pageSize.getWidth();
    const pageHeight = pdf.internal.pageSize.getHeight();
    pdf.setFontSize(10);
    for (let i = 1; i <= totalPages; i++) {
      pdf.setPage(i);
      pdf.text(`Page ${i} / ${totalPages}`, pageWidth / 2, pageHeight - 8, { align: 'center' });
    }
  }).save().then(() => {
    document.body.removeChild(tempContainer);
  }).catch(err => {
    console.error('PDF generation failed', err);
    document.body.removeChild(tempContainer);
    alert('PDF generation failed — check console for details.');
  });
};

document.body.appendChild(script);
