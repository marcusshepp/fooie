// Seperating my JQuery from my HTML.
	$(function() {

	//$('.intro').fadeIn(1000);
	$('h1:contains(CSS Zen Garden)').click(function(){

		$('.summary > p').slideToggle(500);	

    	$(this).toggleText("CSS Zen Garden", "Click to Hide");

	});

	$('h3:contains(The Road to Enlightenment)').click(function(){

		$('.preamble > p').slideToggle(500);

    	$(this).toggleText("The Road to Enlightenment", "Click to Hide");

	});


	$('h3:contains(So What is This About?)').click(function(){

		$('.explanation > p').slideToggle(500);

    	$(this).toggleText("So What is This About?", "Click to Hide");

	});

	$('h3:contains(Participation)').click(function(){

		$('.participation > p').slideToggle(500);

    	$(this).toggleText("Participation", "Click to Hide");

	});

	$('h3:contains(Benefits)').click(function(){

		$('.benefits > p').slideToggle(500);

    	$(this).toggleText("Benefits", "Click to Hide");

	});

	$('h3:contains(Requirements)').click(function(){

		$('.requirements > p').slideToggle(500);

    	$(this).toggleText("Requirements", "Click to Hide");

	});

	$('h3:contains(Archives)').click(function(){

		$('.next, .viewall').slideToggle(500);

    	$(this).toggleText("Archives", "Click to Show");

	});

	$('h3:contains(Resources)').click(function(){

		$('.view-css, .css-resources, .zen-faq, .zen-submit, .zen-translations').slideToggle(500);

    	$(this).toggleText("Resources", "Click to Show");

	});

	$('h3:contains(Select a Design:)').click(function(){

		$( '.designer-name, .design-name, li:contains(by)').slideToggle(500);

		$(this).toggleText("Select a Design:", "Click to Show");

	});

});