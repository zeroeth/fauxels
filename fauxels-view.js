mergeInto(LibraryManager.library, {
	render_pixel: function(index, r, g, b)
	{
		var context = document.getElementById('canvas').getContext('2d');
		var centerX = canvas.width / 2;
		var centerY = canvas.height / 2;

		var radius  = 6;
		var spacing = 0;
		// offset half a circle
		var position = (index + radius/2) * (radius * 2 + spacing);
		var from = 0;
		var to   = 2 * Math.PI;

		context.fillStyle = "rgb("+r+","+g+","+b+")";
		context.beginPath();
		context.arc(position, centerY, radius, from, to);
		context.closePath();
		context.fill();
	},

	initialize_pixels: function(count)
	{
		document.getElementById('canvas').width = count * (12 + 2) + 6
	}
});
